#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const long long INF = (long long)(1000000000);
const int maxn = 100010;

int N, M, P, Q;

int total, p[maxn], rank[maxn], size[maxn];
long long sum[maxn];
vector< pair<int,int> > ans;
set< pair<long long, int> > regions;

int init(int n) {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    rank[i] = 0;
    sum[i] = 0;
    size[i] = 1;
  }
}

int find(int x) {
  return (x == p[x]) ? x : p[x] = find(p[x]);
}

void unite(int x, int y, long long e) {
  int px = find(x);
  int py = find(y);

  if (px == py) {
    sum[px] += e;
    return;
  }

  total--;
  if (rank[px] < rank[py]) {
    p[px] = py;
    regions.erase(make_pair(sum[px], px));
    regions.erase(make_pair(sum[py], py));
    sum[py] += sum[px] + e;
    size[py] += size[px];
    regions.insert(make_pair(sum[py], py));
  }
  else {
    p[py] = px;
    regions.erase(make_pair(sum[px], px));
    regions.erase(make_pair(sum[py], py));
    sum[px] += sum[py] + e;
    size[px] += size[py];
    regions.insert(make_pair(sum[px], px));

    if (rank[px] == rank[py])
      rank[px]++;
  }
}

int count_sets(int n) {
  regions.clear();
  for (int i = 0; i < n; i++)
    regions.insert(make_pair(sum[find(i)], find(i)));
  return regions.size();
}

bool solve() {
  if (regions.size() < Q)
    return false;

  if (M == 0 && regions.size() == Q && P > 0)
    return false;

  set< pair<long long,int> >::iterator it;
  bool first = true;
  int u = -1, v = -1;
  while (P > 0) {
    P--;

    if (regions.size() == Q) {
      if (first) {
        first = false;
        for (u = 0; u < N; u++)
          if (size[find(u)] > 1)
            break;
        u = find(u);
        for (v = 0; v < N; v++)
          if (find(v) == u && v != u)
            break;
      }
      ans.push_back(make_pair(u+1, v+1));
      continue;
    }

    it = regions.begin();
    u = it->second;
    it++;
    v = it->second;
    unite(u, v, min(INF, sum[u]+sum[v]+1));
    ans.push_back(make_pair(u+1, v+1));
  }

  return regions.size() == Q;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> P >> Q;

  init(N);
  for (int i = 0, u, v, e; i < M; i++) {
    cin >> u >> v >> e;
    unite(u-1, v-1, e);
  }
  total = count_sets(N);

  if (!solve())
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first << ' ' << ans[i].second << '\n';
  }

  return 0;
}

