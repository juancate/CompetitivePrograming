#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, feet, inches;
  cin >> n;

  feet = n / 36;
  int r = n % 36;
  inches = r / 3;
  r = r % 3;
  if (r > 1) inches++;

  if (inches == 12) {
    feet++;
    inches = 0;
  }

  cout << feet << ' ' << inches << '\n';

  return 0;
}
