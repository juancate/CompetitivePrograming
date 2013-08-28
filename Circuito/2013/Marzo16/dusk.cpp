#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>

#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

const int INF = 1<<30;

struct Edge {
  int to, out, time;
  Edge(int t = 0, int o = 0, int ti = 0) {
    to = t;
    out = o;
    time = ti;
  }
};

struct State {
  int total_time, current_time, blood, node;
  State(int n = 0, int tt = 0, int ct = -1, int b = 0) {
    total_time = tt;
    current_time = ct;
    blood = b;
    node = n;
  }

  bool operator<(const State& other) const {
    return total_time > other.total_time;
  }
};

vector<Edge> g[111];
map<string, int> c;
int minDist[111];
bool visited[111];

int dijkstra(int s, int t) {
  memset(minDist, 0x3f, sizeof minDist);
  memset(visited, 0, sizeof visited);

  priority_queue<State> pq;
  pq.push(State(s));

  while(!pq.empty()) {
    State curr = pq.top();
    pq.pop();

    if(curr.node == t) {
      return curr.blood;
    }
    if(visited[curr.node]) {
      continue;
    }
    visited[curr.node] = true;

    for(int i = 0; i < g[curr.node].size(); i++) {
      Edge e = g[curr.node][i];
      if(!((e.out >= 18 && (e.out + e.time <= 30)) || (e.out >= 1 && (e.out + e.time <= 6))))
        continue;

      if(curr.current_time == -1) {
        minDist[e.to] = e.time;
        int next_t = e.out + e.time;
        if(next_t > 24) next_t = next_t-24;
        pq.push(State(e.to, e.time, next_t, 0));
        continue;
      }

      int new_blood = curr.blood;

      if(curr.current_time <= 6 && e.out >= 18) new_blood++;
      else if(curr.current_time >= 18 && e.out >= 18 && e.out < curr.current_time) new_blood++;
      else if(curr.current_time <= 6 && e.out < curr.current_time) new_blood++;

      int new_cost = curr.total_time;
      int diff = e.out - curr.current_time;
      if(diff < 0) diff = 24 - curr.current_time + e.out;
      new_cost += diff + e.time;

      if(new_cost < minDist[e.to]) {
        minDist[e.to] = new_cost;
        int next_t = e.out + e.time;
        if(next_t > 24) next_t = next_t-24;
        pq.push(State(e.to, new_cost, next_t, new_blood));
      }
    }
  }

  return INF;
}

int main() {
#ifdef LOCAL
  freopen("dusk.in", "r", stdin);
  freopen("dusk.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
#endif
  int t;
  cin >> t;

  for(int case_id = 1; case_id <= t; case_id++) {
    int m;
    string from, to;
    cin >> m;
    for(int i = 0; i < m; i++) {
      int out, time;
      cin >> from >> to >> out >> time;
      if(!c.count(from)) {
        c[from] = c.size() - 1;
      }
      if(!c.count(to)) {
        c[to] = c.size() - 1;
      }
      g[c[from]].push_back(Edge(c[to], out, time));
    }

    int s, t;
    cin >> from >> to;
    s = c[from];
    t = c[to];
    int ans = dijkstra(s, t);

    cout << "Test Case " << case_id << "." << endl;
    if(ans == INF) {
      cout << "There is no route Vladimir can take." << endl;
    }
    else {
      cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
    }

    c.clear();
    for(int i = 0; i < 111; i++) {
      g[i].clear();
    }
  }

  return 0;
}
