#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

struct Trie {
  bool is_word;
  int counter;
  int edges[26];
};

int N;
Trie t[maxn];

void init(int v) {
  t[v].is_word = false;
  t[v].counter = 0;
  memset(t[v].edges, -1, sizeof t[v].edges);
  N++;
}

void add_word(const string & s) {
  int m = s.size();
  int v = 0;

  for (int i = 0; i < m; i++) {
    int c = s[i] - 'a';
    if (t[v].edges[c] == -1) {
      t[v].edges[c] = N;
      init(N);
    }
    v = t[v].edges[c];
    t[v].counter++;
  }
}

long long dfs(int v) {
  if (t[v].counter == 1)
    return 0;

  long long sum = 0;
  for (int i = 0; i < 26; i++) {
    if (t[v].edges[i] != -1) {
      int next = t[v].edges[i];
      sum += t[next].counter;
      sum += dfs(next);
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    N = 0;
    init(N);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      add_word(s);
    }

    cout << dfs(0) << '\n';
  }

  return 0;
}
