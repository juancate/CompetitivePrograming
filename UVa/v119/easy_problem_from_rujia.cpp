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

int cnt[1000010];
pair< int, pair<int, int> > s[100010];


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        memset(cnt, 0, sizeof(cnt));
        
        REP(i, 0, n) {
            int v; scanf("%d", &v);
            cnt[v]++;
            s[i] = make_pair( v, make_pair(cnt[v], i+1) );
        }
        
        sort(s, s+n);
        
        REP(i, 0, m) {
            int v, k;
            scanf("%d%d", &k, &v);
            
            int pos = int(lower_bound(s, s+n, make_pair(v, make_pair(k, -INF))) - s);
            
            if(pos >= n || s[pos].first != v) {
                puts("0");
            }
            else {
                printf("%d\n", s[pos].second.second);
            }
        }
    }
}

