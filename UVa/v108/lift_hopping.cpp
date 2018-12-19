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
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int n, k, t[5], min_dist[100];
vector<int> g[100], f[5];
bool used[100];

struct state {
    int curr_f, cost, elevator;
    state(int cf = 0, int c = 0, int e = -1) {
        curr_f = cf;
        cost = c;
        elevator = e;
    }

    bool operator<(const state& b) const {
        return cost > b.cost;
    }
};

int dijkstra() {
    priority_queue<state> pq;
    pq.push(state());
    memset(min_dist, 0x3f, sizeof min_dist);
    min_dist[0] = 0;

    while(!pq.empty()) {
        state curr = pq.top();
        int u = curr.curr_f;
        pq.pop();

        if(u == k) {
            return curr.cost;
        }

        if(used[u]) continue;
        used[u] = true;

        foreach(e, g[u]) {
            if(*e == curr.elevator) continue;
            foreach(v, f[*e]) {
                if(u == *v) continue;
                int new_cost = abs(u - *v) * t[*e] + curr.cost + 60;
                if(curr.elevator < 0) new_cost -= 60;
                if(new_cost < min_dist[*v]) {
                    min_dist[*v] = new_cost;
                    pq.push(state(*v, new_cost, *e));
                }
            }
        }

    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n >> k) {
        memset(g, 0, sizeof g);
        memset(f, 0, sizeof f);

        for(int i = 0; i < n; i++)
            cin >> t[i];

        cin.ignore();

        for(int i = 0; i < n; i++) {
            string ln;
            getline(cin, ln);
            stringstream ss(ln);
            int a;
            while(ss >> a) {
                f[i].push_back(a);
                g[a].push_back(i);
            }
        }
        memset(used, 0, sizeof used);
        int ans = dijkstra();
        if(ans < 0) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}
