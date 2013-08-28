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

int numbers[51];

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        REP(i, 0, n) scanf("%d", &numbers[i]);

        int ans = 0, p = 0;

        REP(i, 0, n) {
            REP(j, i+1, n) {
                if(__gcd(numbers[i], numbers[j]) == 1)
                    ans++;
                p++;
            }
        }
        double num = p * 6.;
        if(ans == 0) puts("No estimate for this data set.");
        else printf("%.6lf\n", sqrt(num / ans));
    }
}

