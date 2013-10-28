#include <bits/stdc++.h>

using namespace std;

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

const int maxn = 1010;

int X[maxn], Y[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int,int> Mx, My;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      if (!Mx.count(x))
        Mx[x] = Mx.size() - 1;
      if (!My.count(y))
        My[y] = My.size() - 1;
      X[i] = Mx[x];
      Y[i] = My[y];
    }

    int total = n + n;
    int N = total + 2;
    int source = N-2;
    int sink = N-1;

    PushRelabel mf(N);

    for (int i = 0; i < n; i++)
      mf.addEdge(source, i, 1);
    for (int i = 0; i < n; i++)
      mf.addEdge(i+n, sink, 1);
    for (int i = 0; i < n; i++)
      mf.addEdge(X[i], Y[i]+n, 1);

    cout << mf.getMaxFlow(source, sink) << '\n';
  }

  return 0;
}
