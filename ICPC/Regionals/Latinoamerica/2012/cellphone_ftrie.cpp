#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000010;

struct Trie {
  bool is_word;
  int sons;
  int edges[26];
} t[maxn];
int N;

void initialize(int v) {
  t[v].is_word = false;
  t[v].sons = 0;
  memset(t[v].edges, -1, sizeof(t[v].edges));
  N++;
}

void addWord(const char* s) {
  int v = 0;
  for (int i = 0; s[i]; i++) {
    int c = s[i] - 'a';
    if (t[v].edges[c] == -1) {
      t[v].sons++;
      t[v].edges[c] = N;
      initialize(N);
    }
    v = t[v].edges[c];
  }
  t[v].is_word = true;
}

long long pressed;

void dfs(int u, long long cnt, bool first = false) {
  int next = cnt;

  if (first || t[u].is_word || t[u].sons > 1)
    next++;

  for (int i = 0; i < 26; i++)
    if (t[u].edges[i] != -1)
      dfs(t[u].edges[i], next);

  if (t[u].is_word)
    pressed += cnt;
}

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  int n;
  cout.precision(2);
  cout.setf(ios::fixed);

  while (cin >> n) {
    N = 0;
    initialize(0);

    for (int i = 0; i < n; i++) {
      string w;
      cin >> w;
      addWord(w.c_str());
    }

    pressed = 0;
    dfs(0, 0, true);

    double ans = (double)pressed / (double)n;
    cout << ans << '\n';
  }
  return 0;
}
