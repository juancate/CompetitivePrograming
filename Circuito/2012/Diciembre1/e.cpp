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

int n, m;
vector< vector<int> > G;
int64 cnt;
vector<bool> visited;

void dfs(int u, int first = false) {
    if(visited[u]) {
        cnt++;
        return;
    }
    visited[u] = true;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> m) {
        G.clear();
        G.resize(m);

        cin >> n;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }

        cnt = 0;
        visited.assign(m, false);
        for(int i = 0; i < m; i++) {
            if(!visited[i]) {
                dfs(i, true);
            }
        }
        cout << cnt << endl;
    }
}

