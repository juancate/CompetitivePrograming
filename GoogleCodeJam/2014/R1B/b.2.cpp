#include <bits/stdc++.h>

using namespace std;

string to_bin(int x) {
  if (x == 0)
    return "0";

  string t;
  while (x > 0) {
    t.push_back('0' + (x & 1));
    x >>= 1;
  }

  reverse(t.begin(), t.end());
  return t;
}

string get_diff(string a, string b) {
  int n = a.size();
  int m = b.size();

  return a.substr(0, n-m);
}

string bs;
int len;
long long memo[33][2];

long long get_count(int pos, int tope) {
  if (pos == len)
    return 1;

  if (memo[pos][tope] != -1)
    return memo[pos][tope];

  int limit = tope? bs[pos]-'0' : '1';
  long long r = 0;

  for (int i = 0; i <= limit; i++) {
    r += get_count(pos+1, (i == limit) && tope);
  }

  return memo[pos][tope] = r;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    int a, b, k;
    cin >> a >> b >> k;

    long long ans = 0;

    if (a < b)
      swap(a, b);

    if (k < a && k < b) {
      long long base = k-1;
      string base_string = to_bin(base);
      bs = get_diff(to_bin(a-1), base_string);
      len = bs.size();
      long long curr = get_count(0, 1);
      ans += (curr * base) * base;

      bs = get_diff(to_bin(b-1), base_string);
      len = bs.size();
      curr = get_count(0, 1);
      ans += (curr * base) * base;
    }
    else {
      long long base = a-1;

      string base_string = to_bin(base);
      bs = get_diff(to_bin(k-1), base_string);
      long long curr_k = get_count(0, 1);

      bs = get_diff(to_bin(b-1), base_string);
      len = bs.size();
      long long curr_b = get_count(0, 1);

      if (k <= b) {
        ans += (curr_k * base) * base;
      }
      else {
        ans += (curr_b * base) * base;
      }
    }

    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
  }

  return 0;
}
