#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

#ifdef DEBUG
#include "../../debug.h"
#endif

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int N;

int main() {
    char line[100];
    int cases = 0;
    while(sscanf(gets(line), "%d", &N), N) {
        bool sol = false;
        if(cases++) puts("");

        string seq = "0123456789";

        do {
            string as = seq.substr(0, 5);
            string bs = seq.substr(5);

            int a = atoi(as.c_str());
            int b = atoi(bs.c_str());

            if (a % b == 0 && a / b == N) {
                printf("%s / %s = %d\n", as.c_str(), bs.c_str(), N);
                sol = true;
            }
        } while(next_permutation(ALL(seq)));

        if(!sol) printf("There are no solutions for %d.\n", N);
    }
}

