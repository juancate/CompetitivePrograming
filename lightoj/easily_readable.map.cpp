#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

const int maxn = 100010;
const long long p = 13331;

typedef unsigned long long ull;
#define hash _hash

ull p_pow[maxn];

inline int code(char c) {
  if (islower(c))
    return c - 'a' + 26;
  return c - 'A';
}

ull hash(const string & s) {
  ull h = 0;
  int n = s.size();
  for (int i = 0; i < n; i++)
    h += (code(s[i]) + 1) * p_pow[i];
  return h;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  p_pow[0] = 1;
  for (int i = 1; i <= 100; i++)
    p_pow[i] = p_pow[i-1] * p;

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;

    unordered_map<ull, int> counter;

    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      if (s.size() > 2)
        sort(++s.begin(), --s.end());
      counter[hash(s)]++;
    }

    int m;
    cin >> m;
    cin.get();

    printf("Case %d:\n", tc);
    for (int i = 0; i < m; i++) {
      getline(cin, s);
      stringstream ss(s);

      int ans = 1;
      while (ss >> s) {
        if (s.size() > 2)
          sort(++s.begin(), --s.end());

        ull h = hash(s);
        ans *= (counter.find(h) != counter.end())? counter[h] : 0;
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}
