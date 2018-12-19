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

template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
    return ( os << "(" << z.first << ", " << z.second << ",)" );
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const vector<T>& z){
    os << "[ ";
    REP(i,0,z.size())os << z[i] << ", " ;
    return ( os << "]" << endl);
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const set<T>& z){
    os << "set( ";
    FOREACH(p,z)os << (*p) << ", " ;
    return ( os << ")" << endl);
}
template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
    os << "{ ";
    FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
    return ( os << "}" << endl);
}

const int INF = 1000000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

// Problem : 11506 - Angry Programmer
// Algorithm : Min-cut max flow (Vertex with capacity) Edmonds-Karp

const int MAXN = 100 + 10;

int source, sink, N, E, m, w;
int capacity[MAXN][MAXN], parent[MAXN];
vector< vector<int> > G;
bool visited[MAXN];

struct State {
    int v, priority, from;
    State(int i, int p, int f) : v(i), priority(p), from(f) {}
    bool operator >(const State b) const {
        return priority > b.priority;
    }
    bool operator <(const State b) const {
        return priority < b.priority;
    }
};

// Calculate augmenting path with PFS (Dijkstra modified)
int pfs() {
    priority_queue<State> PQ;
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    PQ.push(State(source, INF, -1));

    int path_capacity = 0;
    int where, next, cost;

    while(!PQ.empty()) {
        State u = PQ.top();
        PQ.pop();
        where = u.v, cost = u.priority;

        if(visited[where]) continue;
        parent[where] = u.from;

        if(where == sink) {
            path_capacity = cost;
            break;
        }

        visited[where] = true;
        REP(next, 0, N) {
            //REP(i, 0, G[where].size()) {
            //  next = G[where][i];
            if(capacity[where][next] > 0) {
                int new_cost = min(cost, capacity[where][next]);
                PQ.push(State(next, new_cost, where));
            }
        }
    }

    if(path_capacity == 0) return 0;

    where = sink;

    while(parent[where] != -1) {
        int prev = parent[where];
        capacity[prev][where] -= path_capacity;
        capacity[where][prev] += path_capacity;
        where = prev;
    }
    return path_capacity;
}


int maxflow() {
    int ret = 0;

    while(true) {
        int flow = pfs();
        if(flow == 0)
            break;
        ret += flow;
    }

    return ret;
}

int main() {
    while(~scanf("%d %d", &m, &w) and (m|w) != 0) {
        N = 2 * m;

        memset(capacity, 0, sizeof(capacity));
        //G.clear();
        //G.resize(N);

        // vertex m - 1 + 1 == server because 2*m vertex
        capacity[0][m] = capacity[m-1][m + m - 1] = INF; // from in to out

        //G[0].push_back(m);
        //G[m-1].push_back(m + m - 1);

        source = 0, sink = m + m - 1;

        REP(i, 0, m - 2) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            capacity[a][m + a] = b;
            //G[a].push_back(m + a);
        }

        REP(i, 0, w) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            capacity[m + a][b] = capacity[m + b][a] = c; // part from out
            //G[m + a].push_back(b);
            //G[m + b].push_back(a);
        }

        int ans = maxflow();
        printf("%d\n", ans);
    }
}

