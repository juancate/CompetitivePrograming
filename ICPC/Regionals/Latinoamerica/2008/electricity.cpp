#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

const int months[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n, d[maxn], m[maxn], y[maxn], a[maxn];

bool is_leap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0);
}

bool is_valid(int i, int j) {
  int day = d[i] + 1;
  int month = m[i];
  int year = y[i];
  if (d[i] >= months[m[i]]) {
    if (m[i] == 2 && is_leap(y[i]) && d[i] < 29)
      day = d[i] + 1;
    else {
      day = 1;
      month++;
      if (month > 12) {
        month = 1;
        year++;
      }
    }
  }

  return day == d[j] && month == m[j] && year == y[j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> d[i] >> m[i] >> y[i] >> a[i];

    int ans = 0, cnt = 0;
    for (int i = 0; i < n-1; i++) {
      if (is_valid(i, i+1)) {
        ans += (a[i+1]-a[i]);
        cnt++;
      }
    }
    cout << cnt << ' ' << ans << '\n';
  }

  return 0;
}
