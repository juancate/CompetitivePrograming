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

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define mp(x,y) make_pair(x, y)
#define pb(x) push_back(x)

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

typedef vector<int> vi;

const int MAXN = 1500 + 10;

int X[MAXN], Y[MAXN], ans[MAXN], size[MAXN];
vi G[MAXN];

int bfs(int v, int parent) {
    size[v] = 1;
    REP(i, 0, G[v].size()) {
        int u = G[v][i];
        if(u != parent) {
            size[v] += bfs(u, v);
        }
    }
    return size[v];
}

bool cmp(int i, int j) {
    return (int64)X[i] * Y[j] - (int64)X[j] * Y[i] < 0;
}

void go(vi p, int v, int parent) {
    int min_i = 0;
    REP(i, 0, p.size()) {
        if (mp(X[p[i]], Y[p[i]]) < mp(X[p[min_i]], Y[p[min_i]]))
            min_i = i;
    }

    swap(p[0], p[min_i]);

    REP(i, 0, p.size()) {
        if(i != 0) {
            X[p[i]] -= X[p[0]];
            Y[p[i]] -= Y[p[0]];
        }
    }

    sort(p.begin() + 1, p.end(), cmp);

    REP(i, 0, p.size()) {
        if(i != 0) {
            X[p[i]] += X[p[0]];
            Y[p[i]] += Y[p[0]];
        }
    }

    int pos = 1, u;
    ans[p[0]] = v;

    REP(i, 0, G[v].size()) {
        u = G[v][i];
        if(u != parent) {
            vi q;
            REP(i, 0, size[u]) {
                q.pb(p[pos++]);
            }
            go(q, u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, u, v;
    cin >> n;

    REP(i, 0, n-1) {
        cin >> u >> v;
        u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    vi p;
    REP(i, 0, n) {
        cin >> X[i] >> Y[i];
        p.pb(i);
    }

    bfs(0, -1);
    go(p, 0, -1);

    REP(i, 0, n) {
        if(i) cout << ' ';
        cout << (ans[i] + 1);
    }
    cout << endl;
}

