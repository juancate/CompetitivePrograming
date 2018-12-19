#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;

const long long p = 13331;
long long p_pow[maxn], h[maxn], ans[maxn * maxn];

int n, ss;
string s, t[2];

void hash_str() {
  for (int i = 0; i < n; i++) {
    h[i] = (s[i]-'a'+1) * p_pow[i];
    if (i > 0) h[i] += h[i-1];
  }
}

vector<int> rabin_karp(int k) {
  int m = t[k].size();
  long long hc = 0;

  for (int i = 0; i < m; i++)
    hc += (t[k][i]-'a'+1) * p_pow[i];

  vector<int> v;
  for (int i = 0; i < n-m+1; i++) {
    long long curr_h = h[i+m-1];
    if (i > 0) curr_h -= h[i-1];

    if (curr_h == hc * p_pow[i])
      v.push_back(i);
  }
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> t[0] >> t[1];
  n = s.size();

  p_pow[0] = 1;
  for (int i = 1; i <= n; i++)
    p_pow[i] = p_pow[i-1] * p;

  hash_str();
  vector<int> bi = rabin_karp(0);
  vector<int> ei = rabin_karp(1);

  int m = t[0].size();
  int k = t[1].size();

  ss = 0;
  for (int i = 0; i < bi.size(); i++) {
    for (int j = 0; j < ei.size(); j++) {
      if (bi[i] <= ei[j] && bi[i] + m <= ei[j] + k) {
        int l = bi[i], r = ei[j] + k;

        long long curr_hash = h[r-1];
        if (l > 0) curr_hash -= h[l-1];

        curr_hash *= p_pow[n-l-1];
        ans[ss++] = curr_hash;
      }
    }
  }

  sort(ans, ans+ss);
  ss = unique(ans, ans+ss) - ans;

  cout << ss << '\n';

  return 0;
}
