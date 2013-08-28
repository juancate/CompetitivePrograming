#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

const unsigned long long p = 13331;
unsigned long long p_pow[maxn], h[maxn], hb, he;

int n, m, l;
string s, b, e;

void hash() {
  for (int i = 0; i < n; i++) {
    h[i] = (s[i]-'a'+1) * p_pow[i];
    if (i > 0) h[i] += h[i-1];
  }
}

bool solve() {
  hash();
  int i;
  bool find = false;

  for (i = 0; i < n-m+1; i++) {
    unsigned long long curr_h = h[i+m-1];
    if (i > 0) curr_h -= h[i-1];

    // set in the same grade both hashes.
    unsigned long long new_hb = hb * p_pow[i];
    if (curr_h == new_hb) {
      find = true;
      i = i+m;
      break;
    }
  }

  if (!find) return false;

  find = false;

  for (; i < n-l+1; i++) {
    unsigned long long curr_h = h[i+l-1];
    if (i > 0) curr_h -= h[i-1];

    // set in the same grade both hashes.
    unsigned long long new_he = he * p_pow[i];
    if (curr_h == new_he) {
      find = true;
      break;
    }
  }

  return find;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> b >> e;
  n = s.size();
  m = b.size();
  l = e.size();

  p_pow[0] = 1;
  for (int i = 1; i <= n; i++)
    p_pow[i] = p_pow[i-1] * p;

  hb = he = 0;
  for (int i = 0; i < m; i++)
    hb += (b[i]-'a'+1) * p_pow[i];
  for (int i = 0; i < l; i++)
    he += (e[i]-'a'+1) * p_pow[i];

  bool forward = solve();
  reverse(s.begin(), s.end());
  bool backward = solve();

  if (forward && backward) cout << "both\n";
  else if (forward) cout << "forward\n";
  else if (backward) cout << "backward\n";
  else cout << "fantasy\n";

  return 0;
}
