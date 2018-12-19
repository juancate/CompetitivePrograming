#include <bits/stdc++.h>

using namespace std;

long long odd1(long long L, long long N) {
  if (L == 1)
    return (N == 1)? 4 : 0;

  long long total = 2 * (L >> 1) * ((L >> 1) + 1);
  long long ret = total << 2;

  if (N > total) {
    if (N > total + 4) {
      total += 4;
      long long res = L - (L >> 1) - 2; // avail sq
      if (N > total + 4*res) {
        total += 4*res;
        N -= total;
        ret = ret - 8*res - 4*N;
      }
      else {
        N -= total;
        ret -= N * 2;
      }
    } // else same perimeter
  }
  else ret = 4*N;
  return ret;
}

long long odd2(long long L, long long N) {
  long long total = 2 * (L >> 1) * ((L >> 1) + 1) + 1;
  long long ret = total << 2;

  if (N > total) {
    long long res = (L >> 1);
    if (N > total + 4*res) {
      total += 4*res;
      N -= total;
      ret = ret - 8*res - 4*N;
    }
    else {
      N -= total;
      ret -= N * 2;
    }
  }
  else ret = 4*N;

  return ret;
}

long long even(long long L, long long N) {
  long long total = (L >> 1) * L;
  long long ret = total << 2;

  if (N > total) {
    if (N > total + 2) {
      total += 2;
      long long res = L - (L >> 1) - 1;
      if (N > total + 4*res) {
        total += 4*res;
        N -= total;
        ret = ret - 8*res - 4*N;
      }
      else {
        N -= total;
        ret -= N * 2;
      }
    }
  }
  else ret = 4*N;

  return ret;
}

void solve(long long L, long long N) {
  long long ans = (L & 1)? max(odd1(L,N), odd2(L,N)) : even(L,N);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long L, N;
  while (cin >> L >> N) {
    if ((L|N) == 0)
      break;
    solve(L,N);
  }

  return 0;
}
