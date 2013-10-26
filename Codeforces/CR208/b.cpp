#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 100010;

int n, m, k;
string dict[maxn], w;

bool check(string s) {
  int N = s.size();
  for (int i = 0; i < N; i++) {
    while (k < m && w[k] != s[i]) k++;
    if (k >= m || w[k] != s[i])
      return false;
    k++;
  }
  return true;
}

string solve() {
  k = 0;
  for (int i = 0; i < n; i++) {
    if (!check("<3") || !check(dict[i]))
      return "no";
  }
  if (!check("<3"))
    return "no";
  return "yes";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> dict[i];
  cin >> w;
  m = w.size();

  cout << solve() << '\n';

  return 0;
}

