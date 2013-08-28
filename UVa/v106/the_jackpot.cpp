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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 10000;

int a[MAXN], n;

int main() {
    while(~scanf("%d", &n), n) {
        REP(i, 0, n) scanf("%d", &a[i]);

        int max_sum = -INF;
        int current_sum = 0;

        for(int i = 0, j = 0; j < n; j++) {
            current_sum = max(a[j], current_sum + a[j]);
            max_sum = max(max_sum, current_sum);
        }
        if(max_sum <= 0) puts("Losing streak.");
        else printf("The maximum winning streak is %d.\n", max_sum);
    }
}

