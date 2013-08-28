#include <bits/stdc++.h>

using namespace std;

int n, a[20];
long long memo[20][1<<20][2], ans[20];

long long solve(int pos, int mask, int ord) {
  if (mask == (1<<n)-1)
    return 1LL;

  if (memo[pos][mask][ord] != -1)
    return memo[pos][mask][ord];

  long long r = 0;
  for (int i = 0; i < n; i++) {
    if ((mask & (1<<i)) == 0) {
      if (ord == 0 && a[i] < a[pos])
        r += solve(i, mask | (1 << i), ord^1);
      else if (ord == 1 && a[pos] < a[i])
        r += solve(i, mask | (1 << i), ord^1);
    }
  }
  return memo[pos][mask][ord] = r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < 21; i++) {
    n = i;
    memset(memo, -1, sizeof(memo));
    for (int j = 1; j <= i; j++)
      a[j-1] = j;
    ans[i] = 0;
    for (int j = 0; j < i; j++) {
      ans[i] += solve(j, (1 << j), 0);
      ans[i] += solve(j, (1 << j), 1);
    }
  }
  ans[1] = 1;

  cout << "#include <bits/stdc++.h>\n\n";
  cout << "using namespace std;\n\n";
  cout << "long long ans[] = {";
  for (int i = 1; i < 21; i++) {
    if (i > 1) cout << ", ";
    cout << ans[i] << "LL";
  }
  cout << "};\n\n";
  cout << "int main() {\n";
  cout << "}\n";

  return 0;
}
