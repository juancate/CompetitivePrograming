#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

struct Trie {
  bool word;
  int edges[26];
};

int n, m, N, M, suffix_count[26];
bool start[26];
long long ans = 0;
Trie prefix[maxn], suffix[maxn];

void init(Trie * t, int v, int & sz) {
  t[v].word = false;
  memset(t[v].edges, -1, sizeof t[v].edges);
  sz++;
}

void add_prefix(const string & s) {
  int len = s.size();
  int v = 0;

  for (int i = 0; i < len; i++) {
    int c = s[i] - 'a';
    if (prefix[v].edges[c] == -1) {
      prefix[v].edges[c] = N;
      init(prefix, N, N);
    }
    v = prefix[v].edges[c];
  }
  prefix[v].word = true;
}

void add_suffix(const string & s) {
  int len = s.size();
  int v = 0;
  start[ s[len-1] - 'a' ] = true;

  for (int i = len-1; i >= 0; i--) {
    int c = s[i] - 'a';
    if (suffix[v].edges[c] == -1) {
      suffix[v].edges[c] = M;
      init(suffix, M, M);

      suffix_count[c]++; // new suffix
    }
    v = suffix[v].edges[c];
  }
  suffix[v].word = true;
}

void solve(int v) {
  for (int i = 0; i < 26; i++) {
    if (prefix[v].edges[i] != -1) {
      solve(prefix[v].edges[i]);
      if (v > 0 && start[i])
        ans++;
    }
    else {
      if (v > 0) // not root
        ans += suffix_count[i];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    N = M = 0;
    init(prefix, 0, N);
    init(suffix, 0, M);

    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      add_prefix(s);
    }

    memset(start, 0, sizeof start);
    memset(suffix_count, 0, sizeof suffix_count);

    for (int i = 0; i < m; i++) {
      cin >> s;
      add_suffix(s);
    }

    ans = 0;
    solve(0);

    cout << ans << '\n';
  }

  return 0;
}
