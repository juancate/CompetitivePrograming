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

char s[64];
int cnt[64];

int main() {
    int t, n, m, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            for(int j = 0; j < m; j++) {
                cnt[i] += (s[j] == '*');
            }
        }

        while(k) {
            sort(cnt, cnt+n);
            cnt[0] = m - cnt[0];
            k--;
        }
        printf("%d\n", accumulate(cnt, cnt+n, 0));
    }
    return 0;
}

