#include <bits/stdc++.h>

using namespace std;

const int maxn = 44;

int N, M, G, m[maxn][maxn], l[maxn], points[maxn];

const long long INF = int(1e9);

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector< vector<Edge> > G;
  vector<long long> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void addEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void enqueue(int v) {
    if (!active[v] && excess[v] > 0) {
      active[v] = true;
      Q.push(v);
    }
  }

  void push(Edge& e) {
    int amt = int(min(excess[e.from], (long long)(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0)
      return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    enqueue(e.to);
  }

  void gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k)
        continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      enqueue(v);
    }
  }

  void relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    enqueue(v);
  }

  void discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++)
      push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
        gap(dist[v]);
      else
        relabel(v);
    }
  }

  long long getMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      discharge(v);
    }

    long long totflow = 0;
    for (int i = 0; i < G[s].size(); i++)
      totflow += G[s][i].flow;

    return totflow;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> N >> M >> G) {
    if ((N|M|G) == 0)
      break;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        if (i != j) m[i][j] = M;
      l[i] = M * (N-1);
      points[i] = 0;
    }

    for (int i = 0; i < G; i++) {
      int a, b;
      char r;
      cin >> a >> r >> b;

      if (r == '=')
        points[a]++, points[b]++;
      else
        points[b] += 2;
      l[a]--, l[b]--;
      m[a][b]--, m[b][a]--;
    }

    for (int i = 1; i < N; i++) {
      if (m[0][i] > 0) {
        int curr = m[0][i];
        points[0] += curr * 2;
        G += curr;
        l[i] -= curr;
        m[0][i] = m[i][0] = 0;
      }
    }

    int n = N + 2;
    int source = N;
    int sink = source + 1;

    bool can = true;
    PushRelabel mf(n);

    for (int i = 1; i < N; i++) {
      int cap = 0;
      for (int j = i+1; j < N; j++) {
        int curr = m[i][j] * 2;
        cap += curr;
        mf.addEdge(i, j, curr);
      }
      mf.addEdge(source, i, cap);

      int a = points[0] - points[i] - 1;
      int b = l[i] * 2;

      if (a < 0) {
        can = false;
        break;
      }
      mf.addEdge(i, sink, min(a, b));
    }

    if (can) {
      long long flow = mf.getMaxFlow(source, sink);
      long long total_matches = N * (N-1) * M;
      long long matches_left = total_matches - 2 * G;

      cout << (flow == matches_left? 'Y' : 'N') << '\n';
    }
    else cout << "N\n";
  }

  return 0;
}
