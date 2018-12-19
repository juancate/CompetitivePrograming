#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, a, b, v;
  cin >> k >> a >> b >> v;

  int boxes = 0;
  while (a > 0) {
    int sections = min(k-1, b);
    if (b == 0)
      sections = 1;
    else {
      b -= sections;
      sections++;
    }

    a -= min(v * sections, a);
    boxes++;
  }
  cout << boxes << '\n';

  return 0;
}
