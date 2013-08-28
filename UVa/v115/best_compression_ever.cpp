#include <bits/stdc++.h>

using namespace std;

int msb(long long N) {
  int j = 0;
  for (int i = 0; i <= 51; i++) {
    if (N & (1LL << i))
      j = i;
  }
  return j;
}

void solve(long long N, int b) {
  if (b == 0) {
    if (N == 0) cout << "yes\n";
    else cout << "no\n";
  }
  else {
    int most = msb(N);
    long long limit = (1LL << (most+1)) - 1;
    if (limit > N) most--;

    if (most+1 > b) cout << "no\n";
    else cout << "yes\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N;
  int b;
  while (cin >> N >> b) {
    N--;
    solve(N, b);
  }

  return 0;
}
