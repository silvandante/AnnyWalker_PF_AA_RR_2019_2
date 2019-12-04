
#include <list>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>

#include <chrono>
using namespace std;

#define MAX_COLORS 1001

vector<int> Color(MAX_COLORS,-1);

class Graph {
    int V;
    list<int> *adj;
    public:
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }

    void addEdge(int v, int w);

    void greedyColoring();

    bool backtrackingColoring(int u);
    bool isSafe(int u,int color);
    void printResult();
};


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::greedyColoring()  {
    int result[V];

    result[0]  = 0;

    for (int u = 1; u < V; u++)
        result[u] = -1;

    bool available[V];
    for (int cr = 0; cr < V; cr++) {
        available[cr] = false;
    }
 auto t1 = std::chrono::high_resolution_clock::now();
    for (int u = 1; u < V; u++){
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr;

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
     auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
printf("%d\n", V);
    std::cout << "Duração em ms: " << duration << "\n";


    for (int u = 0; u < V; u++)
        cout << "Vertice " << u << " --->  Color "
             << result[u] << endl;

}

bool Graph::isSafe(int u,int color){
    list<int>::iterator it;

    for(it=adj[u].begin();it!=adj[u].end();++it){
        if(Color[*it] == color) return false;
    }
    return true;
}


// Driver program to test above function
int main() {
printf("%d\n", INT_MAX);

    Graph g1(77305);

	std::ifstream file("4-FullIns_5_77305.col");
	if (file.is_open()) {
	    std::string line;
	    while (getline(file, line)) {
	        // using printf() in all tests for consistency
	        char * cstr = new char [line.length()+1];
	        std::strcpy (cstr, line.c_str());
	        char * p = std::strtok (cstr," ");
	        int array[3];

	        for (int i = 0; i<3; i++){
	        	//std::cout << p << ' ';
			    p = std::strtok(NULL," ");
			    array[i] = atoi(p);
			}

			  	g1.addEdge(array[1],array[2]);
			//	printf("\n");
			  delete[] cstr;
	    }
	    file.close();
	}

    g1.greedyColoring();

    system("pause");
    return 0;
}
