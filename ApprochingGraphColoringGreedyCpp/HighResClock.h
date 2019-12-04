
#include <list>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <HighResClock.h>

struct HighResClock
    {
        typedef long long                               rep;
        typedef std::nano                               period;
        typedef std::chrono::duration<rep, period>      duration;
        typedef std::chrono::time_point<HighResClock>   time_point;
        static const bool is_steady = true;

        static time_point now();
    };
