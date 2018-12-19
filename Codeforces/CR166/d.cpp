#include <bits/stdc++.h>

using namespace std;

// Algorithm: Hashing

const int maxn = 1510;

const long long p = 13331;
long long p_pow[maxn], h[maxn];

int k, n, bad[27], bad_count[maxn];
string s, b;

void hash() {
  for (int i = 0; i < n; i++) {
    h[i] = (s[i] - 'a' + 1) * p_pow[i];
    if (i > 0) h[i] += h[i-1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  p_pow[0] = 1;
  for (int i = 1; i < maxn; i++)
    p_pow[i] = p_pow[i-1] * p;

  cin >> s >> b >> k;
  n = s.size();

  for (int i = 0; i < b.size(); i++)
    bad[i] = b[i] == '0';

  bad_count[0] = bad[s[0]-'a'];
  for (int i = 1; i < n; i++)
    bad_count[i] = bad_count[i-1] + bad[s[i]-'a'];

  hash();
  set<long long> ans;

  for (int lenght = 1; lenght <= n; lenght++) {
    vector<long long> hs(n - lenght + 1);

    for (int i = 0; i < n-lenght+1; i++) {
      int bads = bad_count[i+lenght-1];
      if (i > 0) bads -= bad_count[i-1];

      if (bads > k) continue;

      long long curr_hash = h[i+lenght-1];
      if (i > 0) curr_hash -= h[i-1];

      curr_hash *= p_pow[n-i-1];
      hs[i] = curr_hash;
      ans.insert(hs[i]);
    }
  }

  cout << ans.size() << '\n';

  return 0;
}
