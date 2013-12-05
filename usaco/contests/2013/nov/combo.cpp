#include <bits/stdc++.h>

using namespace std;

ifstream in("combo.in");
ofstream out("combo.out");

void redirect() {
  cin.rdbuf(in.rdbuf());
  cout.rdbuf(out.rdbuf());
}

int N, key[3], master[3];

bool can_key(int i, int j, int k) {
  if (abs(i-key[0]) <= 2)
    return false;
  if (abs(j-key[1]) <= 2)
    return false;
  if (abs(k-key[2]) <= 2)
    return false;
  return true;
}

bool can_master(int i, int j, int k) {
}

bool can(int i, int j, int k) {
  return can_key(i,j,k) || can_master(i,j,k);
}

int solve() {
  int ans = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      for (int k = 1; k <= N; k++)
        if (can(i,j,k))
          ans++;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef LOCAL
  redirect();
#endif

  while (cin >> N) {
    for (int i = 0; i < 3; i++)
      cin >> key[i];
    for (int i = 0; i < 3; i++)
      cin >> key[i];

    cout << solve() << '\n';
  }

  in.close();
  out.close();

  return 0;
}
