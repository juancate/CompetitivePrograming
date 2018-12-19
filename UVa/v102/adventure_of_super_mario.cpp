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

#define mp make_pair

int A, B, L, K;
vector< pair<int,int> > G[110];
int minDist[110][510][11];
bool visited[110][510][11];


struct State
{
    int u, time, turbos, turbo_distance;

    State(int _u = 0, int _time = 0, int _turbos = 0, int _turbo_distance = 0)
    {
        u = _u;
        time = _time;
        turbos = _turbos;
        turbo_distance = _turbo_distance;
    }

    bool operator<(const State& other) const
    {
        return time > other.time;
    }
};

bool is_castle(int u) {
    return u >= A && u < A+B;
}

bool check_best(int cost, const State& next) {
    if(cost < minDist[next.u][next.turbo_distance][next.turbos]) {
        minDist[next.u][next.turbo_distance][next.turbos] = cost;
        return true;
    }
    return false;
}

int dijkstra(int start, int end)
{
    memset(minDist, 0x3f, sizeof(minDist));
    memset(visited, false, sizeof(visited));

    priority_queue<State> Q;

    Q.push( State(start, 0, K, L) );
    minDist[start][L][K] = 0;

    while(!Q.empty()) {
        State current = Q.top();
        Q.pop();

        if(current.turbos < 0)
            continue;

        if(current.u == end) {
            return current.time;
        }

        if(visited[current.u][current.turbo_distance][current.turbos])
            continue;

        visited[current.u][current.turbo_distance][current.turbos] = true;

        for(int i = 0; i < (int)G[current.u].size(); i++) {

            pair<int, int> v = G[current.u][i];

            if(is_castle(v.first)) {
                // use turbo
                if(v.second <= L && current.turbos > 0) {
                    State next = State(v.first, current.time, current.turbos-1, L);
                    // check best
                    if(check_best(current.time, next)) {
                        //D(next.u); D(next.time);
                        Q.push(next);
                    }
                }

                if(current.turbo_distance + v.second <= L) {
                    State next = State(v.first, current.time, current.turbos, L);
                    // check best
                    if(check_best(current.time, next))
                        Q.push(next);
                }
                // no use turbo
                State next = State(v.first, current.time + v.second, current.turbos, L);
                //check best
                if(check_best(current.time + v.second, next))
                    Q.push(next);
            }
            else { // ville
                if(current.turbo_distance + v.second <= L) {
                    State next = State(v.first, current.time,
                                       current.turbos, current.turbo_distance + v.second);
                    // check best
                    if(check_best(current.time, next))
                        Q.push(next);

                }
                if(v.second <= L && current.turbos > 0) {
                    State next = State(v.first, current.time,
                                       current.turbos - 1, v.second);
                    // check best
                    if(check_best(current.time, next))
                        Q.push(next);

                }
                State next = State(v.first, current.time + v.second, current.turbos, L);
                if(check_best(current.time + v.second, next))
                    Q.push(next);
                //check best
            }
        }
    }

    return -1;
}



int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int m;
        scanf("%d%d%d%d%d", &A, &B, &m, &L, &K);

        for(int i = 0; i < A+B; i++)
            G[i].clear();

        for(int i = 0; i < m; i++) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            G[a].push_back( mp(b, c) );
            G[b].push_back( mp(a, c) );
        }

        int ans = dijkstra(A+B-1, 0);
        printf("%d\n", ans);
    }

}

