#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int main() {
  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;
  bool dragons[d+1];
  memset(dragons, false, sizeof(dragons));

  for(int i = 1; ; i++) {
    int mult = k * i;
    if(mult <= d) dragons[mult] = true;
    else break;
  }

  for(int i = 1; ; i++) {
    int mult = l*i;
    if(mult <= d) dragons[mult] = true;
    else break;
  }

  for(int i = 1; ; i++) {
    int mult = m*i;
    if(mult <= d) dragons[mult] = true;
    else break;
  }

  for(int i = 1; ; i++) {
    int mult = n*i;
    if(mult <= d) dragons[mult] = true;
    else break;
  }
  int ans = 0;
  for(int i = 1; i <= d; i++) if(dragons[i]) ans++;
  cout << ans << endl;

  return 0;
}
