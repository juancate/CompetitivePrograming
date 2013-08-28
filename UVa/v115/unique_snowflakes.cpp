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

int v[1000010], p[1000010];

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        map<int, int> last;

        for(int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            p[i] = last[v[i]];
            last[v[i]] = i;
        }

        int ans, prev, curr;
        ans = 0, prev = curr = 1;

        for(curr = 1; curr <= n; curr++) {
            if(p[curr] >= prev) {
                ans = max(ans, curr - prev);
                prev = p[curr] + 1;
            }
        }

        ans = max(ans, curr - prev);

        printf("%d\n", ans);
    }
    return 0;
}

