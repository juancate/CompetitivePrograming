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

typedef pair<int,int> ii;
#define mp make_pair

const int maxn = 1010;
const int maxnn = 2*1010;

int n, source, sink;
int rooms[maxn], parent[maxnn];
int64 capacity[maxnn][maxnn];
bool visited[maxnn];

vector< ii > G[maxnn];

struct State
{
    int v, from;
    int64 priority;
    State(int i, int64 p, int f) : v(i), priority(p), from(f) {}
    bool operator>(const State& b) const {
        return priority > b.priority;
    }
    bool operator<(const State& b) const {
        return priority < b.priority;
    }
};

int64 pfs() {
    priority_queue<State> PQ;
    memset(visited, false, sizeof visited);
    memset(parent, -1, sizeof parent);

    PQ.push(State(source, INF, -1));

    int64 path_capacity = 0;
    int where, next;
    int64 cost;

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
        for(next = 0; next < 2*n; next++) {
            if(capacity[where][next] > 0) {
                int64 new_cost = min(cost, capacity[where][next]);
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

int64 maxflow() {
    int64 max_flow = 0;

    while(true) {
        int64 flow = pfs();
        if(flow == 0)
            break;
        max_flow += flow;
    }

    return max_flow;
}

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        for(int i = 0; i <= n; i++)
            G[i].clear();
        source = 0;
        sink = 0;

        for(int i = 0; i < n; i++) {
            cin >> rooms[i];
            if(rooms[source] > rooms[i])
                source = i;
            if(rooms[sink] < rooms[i])
                sink = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int p = __gcd(rooms[i], rooms[j]);
                if(p != 1) {
                    G[i].push_back( mp(j, p) );
                    G[j].push_back( mp(i, p) );
                }
            }
        }
        memset(capacity, 0, sizeof capacity);
        for(int i = 0; i < n; i++) {
            capacity[i][i+n] = capacity[i+n][i] = rooms[i];
            for(int j = 0; j < (int)G[i].size(); j++) {
                int v = G[i][j].first;
                capacity[i+n][v] = G[i][j].second;
                capacity[v+n][i] = G[i][j].second;
            }
        }
        /*
        for(int i = 0; i < n+n; i++) {
            for(int j = 0; j < n+n; j++) {
                cerr << capacity[i][j] << " ";
            }
            cerr << endl;
        }
        */
        sink = sink + n;
        //D(source); D(sink);
        cout << maxflow() << endl;
    }
}

