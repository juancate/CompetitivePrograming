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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 111;

int sink, source, N;
int capacity[MAXN][MAXN], parent[MAXN];
bool visited[MAXN];

struct State {
    int v, priority, from;
    State(int i, int p, int f) : v(i), priority(p), from(f) {}

    bool operator <(const State b) const {
        return priority < b.priority;
    }
};

int pfs() {
    priority_queue<State> PQ;
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    PQ.push(State(source, INF, -1));

    int path_capacity = 0;
    int where, cost;

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
    int max_flow = 0;

    while(true) {
        int flow = pfs();
        if(flow == 0)
            break;
        max_flow += flow;
    }
    return max_flow;
}

int main() {
    int numCases = 1, m;
    while(~scanf("%d", &N), N) {
        scanf("%d%d%d", &source, &sink, &m);
        source--, sink--;

        memset(capacity, 0, sizeof(capacity));

        REP(i, 0, m) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            capacity[a][b] = capacity[b][a] += c;
        }

        printf("Network %d\n", numCases++);
        printf("The bandwidth is %d.\n\n", maxflow());
    }
}

