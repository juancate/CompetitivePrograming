#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  int n, i, x;
  double ans;
  priority_queue<int> q;

  scanf("%d", &n);
  for(i = 0; i <= n>>1; i++) {
    scanf("%d", &x);
    q.push(x);
  }

  for(i = (n>>1)+1; i < n; i++) {
    scanf("%d", &x);
    q.push(x);
    q.pop();
  }

  ans = q.top();
  q.pop();

  if(!(n & 1)) {
    ans += q.top();
    ans /= 2.;
  }
  printf("%.1lf\n", ans);

  return 0;
}
