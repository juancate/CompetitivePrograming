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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define foreach(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    map<int64, int> g;
    for(int i = 0; i < n; i++) {
        int64 x;
        cin >> x;
        g[x] = 0;
        if(k == 1) continue;
        if(x % k == 0 && g.count(x / k)) {
            g[x]++;
            g[x/k]++;
        }
        if(g.count(x * k)) {
            g[x]++;
            g[x*k]++;
        }
    }

    int ans = n;

    foreach(v, g) {
        int64 x = v->first;
        if(v->second == 2) {
            if(x % k == 0 && g.count(x/k))
                g[x/k]--;
            if(g.count(x*k))
                g[x*k]--;
            ans--;
        }
    }

    foreach(v, g) {
        int64 x = v->first;
        if(v->second == 1) {
            if(x % k == 0 && g.count(x/k))
                g[x/k]--;
            if(g.count(x*k))
                g[x*k]--;
            ans--;
        }
    }

    cout << ans << endl;
}

