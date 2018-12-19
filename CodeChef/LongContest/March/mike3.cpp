#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int n;
vector<int> g[N];
bool adj[N][N];

bool intersect(int a, int b) {
  for (int i = 0, j = 0; i < g[a].size(); i++) {
    while (j < g[b].size() && g[b][j] < g[a][i])
      j++;

    if (j >= g[b].size())
      break;

    if (g[a][i] == g[b][j])
      return true;
  }
  return false;
}

int clique(vector<int> path, int pos, int card) {
  if (pos >= n)
    return card;

  int ret = max(card, clique(path, pos+1, card));

  bool can = true;
  for (int i = 0; i < path.size(); i++)
    if (!adj[pos][path[i]])
      can = false;

  path.push_back(pos);
  if (can)
    ret = max(ret, clique(path, pos+1, card+1));

  return ret;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m;
  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      g[i].push_back(s);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      adj[i][j] = !intersect(i, j);
      adj[j][i] = adj[i][j];
    }
  }

  int best = 0;

  for (int i = 0; i < n; i++) {
    vector<int> path;
    best = max(best, clique(path, i, 0));
  }

  cout << best << '\n';

  return 0;
}
