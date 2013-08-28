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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

typedef pair<int, int> ii;
typedef pair< double, pair<int, int> > dii;
typedef vector<ii> vii;

#define mp make_pair
#define sp first
#define node second.second
#define dist second.first

const int MAXN = 111;

vector<vii> G;
int exits[MAXN], police, brothers, n;
double time_needed[MAXN];
bool is_exit[MAXN];

void dijkstra_police(int start) {
    vector<bool> visited(n, false);
    vector<int> d(n, INF);
    memset(time_needed, 0, sizeof(time_needed));

    priority_queue<ii> Q;
    Q.push( mp(0, start) );
    d[start] = 0;

    while(!Q.empty()) {
        int v = Q.top().second;
        int cost = -Q.top().first;
        Q.pop();

        if(visited[v]) continue;
        visited[v] = true;

        FOREACH(u, G[v]) {
            int new_cost = cost + u->second;
            if(new_cost < d[u->first]) {
                d[u->first] = new_cost;
                Q.push( mp(-new_cost, u->first) );
            }
        }
    }

    REP(i, 0, n)
        time_needed[i] = d[i] / 160.;
}

double dijkstra_brothers(int start) {
    vector<bool> visited(n, false);
    vector<double> min_speed(n, INF);

    priority_queue< dii, vector<dii>, greater<dii> > Q;
    Q.push( mp(0.0, mp(0, start)) );

    min_speed[start] = 0;

    while(!Q.empty()) {
        int v = Q.top().node;
        int cost = Q.top().dist;
        double speed = Q.top().sp;
        Q.pop();

        if(visited[v]) continue;
        visited[v] = true;

        if(is_exit[v]) {
            return min_speed[v] = speed;
        }

        if(v == police) continue;

        FOREACH(u, G[v]) {

            if(!visited[u->first]) {
                int new_dist = cost + u->second;
                double new_speed = max(speed, new_dist / time_needed[u->first]);

                if(new_speed < min_speed[u->first]) {
                    min_speed[u->first] = new_speed;
                    Q.push( mp(min_speed[u->first], mp(new_dist, u->first)) );
                }
            }
        }
    }
    return -1;
}

int main() {
    int N; scanf("%d", &N);

    while(N--) {
        int m, e; scanf("%d%d%d", &n, &m, &e);

        G.assign(n, vii());
        fill(is_exit, is_exit+n+1, false);

        REP(i, 0, m) {
            int a, b, l; scanf("%d%d%d", &a, &b, &l); a--, b--;
            G[a].push_back( mp(b, l) );
            G[b].push_back( mp(a, l) );
        }

        REP(i, 0, e) {
            int a; scanf("%d", &a); a--;
            exits[i] = a;
            is_exit[a] = true;
        }

        scanf("%d%d", &brothers, &police); brothers--, police--;

        dijkstra_police(police);
        double ans = dijkstra_brothers(brothers);

        if(ans < 0) puts("IMPOSSIBLE");
        else printf("%.10lf\n", ans);
    }
}

