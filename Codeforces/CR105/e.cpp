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

typedef vector<vector<int> > vvi;

int n, m;
vvi items;
int memo[100+1][100+1][100+1];

int solve(int i, int j, int l, int s) {
  if(l < j) return 0; // Evaluar el siguiente
  if(i >= n) return 0;
  if(s > m) return 0;
  if(memo[i][j][l] != -1) return memo[i][j][l];
  int a, b = 0, c = 0;
  a = solve(i+1, j, l, s);
  if(s+1 <= m) {
    b = items[i][j] + solve(i, j+1, l, s+1);
    c = items[i][l] + solve(i, j, l-1, s+1);
  }
  return memo[i][j][l] = max(a, max(b, c));
}

int main() {
  cin >> n >> m;
  items.resize(n);
  REP(i,n) {
    int x; cin >> x;
    items[i].resize(x);
    REP(j, x) {
      cin >> items[i][j];
    }
  }
  memset(memo, -1, sizeof(memo));
  int ans = solve(0, 0, items[0].size() - 1, 0, 0, 0);
  cout << ans << endl;
}
