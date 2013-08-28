#line 107 "WorkingRabbits.cpp"

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
#include <limits>
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define ALL_BITS 0xFFFFFFFF
#define INF (int)(1e9)
#define INFLL (long long)(1e18)
#define EPS (1e-19)

using namespace std;

class WorkingRabbits {
public:
    double getEfficiency(vector <string> profit) {
        double sum = 0.0;
        int n = profit.size();
        int m = profit[0].size();
        int p = 0;
        REP(i, 0, n) {
            REP(j, i+1, m) {
                sum += (profit[i][j] - '0');
                p++;
            }
        }
        return (sum / p);
    }
};



// Powered by FileEdit
// Powered by moj 4.17 [modified TZTester]
// Powered by CodeProcessor
