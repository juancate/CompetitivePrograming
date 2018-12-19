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

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int sides[3];

int main() {
    while(~scanf("%d%d%d", &sides[0], &sides[1], &sides[2])) {
        if(sides[0] == 0 && sides[1] == 0 && sides[2] == 0)
            break;

        sort(sides, sides + 3);

        if((sides[2] * sides[2]) == (sides[0] * sides[0] + sides[1] * sides[1]))
            puts("right");
        else
            puts("wrong");
    }
}

