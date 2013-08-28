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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

#define mp make_pair

const int maxn = 100010;

int n, m;
vector< pair<int, int> > G[maxn];
vector< vector<int> > travellers;
bool visited[maxn];
int64 dist[maxn];

int64 find_wait(int to, int64 time) {
    int pos = int(lower_bound(ALL(travellers[to]), time) - travellers[to].begin());

    for(int i = pos; i < (int)travellers[to].size(); i++) {
        if(travellers[to][i] != time) {
            return time;
        }
        time++;
    }
    return time;
}

int64 dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(visited, false, sizeof(visited));

    priority_queue< pair<int64, int> > Q;
    Q.push( mp(0, 1) );
    dist[1] = 0;

    while(!Q.empty()) {
        int64 time = -Q.top().first;
        int u = Q.top().second;
        Q.pop();

        if(u == n) return time;

        if(visited[u]) continue;
        visited[u] = true;

        int64 wait = find_wait(u, time);

        for(int j = 0; j < (int)G[u].size(); j++) {
            pair<int, int> v = G[u][j];
            int64 new_time = wait + v.second;

            if(new_time < dist[v.first]) {
                dist[u] = new_time;

                Q.push( mp(-new_time, v.first) );
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        G[a].push_back( mp(b, c) );
        G[b].push_back( mp(a, c) );
    }

    travellers.resize(n+1);

    for(int i = 1; i < n; i++) {
        int ki; cin >> ki;
        for(int j = 0; j < ki; j++) {
            int x; cin >> x;
            travellers[i].push_back(x);
        }
    }

    int64 ans = dijkstra();

    cout << ans << endl;
}

