#include <bits/stdc++.h>

using namespace std;

int A, B, total;

inline
int get_watts(int x) {
  int r = 0;

  if (x <= 200)
    return x / 2;
  else {
    r += 100;
    x -= 2 * 100;
    if (x <= 3 * 9900)
      return r + (x / 3);
    else {
      r += 9900;
      x -= 3 * 9900;
      if (x <= 5 * 990000)
        return r + (x / 5);
      else {
        r += 990000;
        x -= 5 * 990000;
        r += x / 7;
      }
    }
  }

  return r;
}

inline
long long get_price(int x) {
  long long r = 0;

  if (x <= 100)
    r += 2 * x;
  else {
    r += 2 * 100;
    x -= 100;
    if (x <= 9900)
      r += 3 * x;
    else {
      r += 3 * 9900;
      x -= 9900;
      if (x <= 990000)
        r += 5 * x;
      else {
        r += 5 * 990000;
        x -= 990000;
        r += 7 * x;
      }
    }
  }

  return r;
}

bool can(int x) {
  int y = total-x;
  return get_price(y)-get_price(x) <= B;
}

long long solve() {
  total = get_watts(A);
  int lo = 0, hi = total / 2;

  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (can(mid)) hi = mid;
    else lo = mid+1;
  }
  return get_price(lo);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> A >> B) {
    if ((A|B) == 0)
      break;

    cout << solve() << '\n';
  }

  return 0;
}
