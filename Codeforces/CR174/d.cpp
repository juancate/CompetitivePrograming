#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int maxn = 200010;

int n;
long long a[maxn], memo[3][maxn];
bool used[3][maxn];

long long solve(long long x, int cmd) {
  if(x <= 0 || x > n) return 0;

  if(memo[cmd][x]) return memo[cmd][x];

  if(used[cmd][x]) {
    return memo[cmd][x] = -1;
  }

  used[cmd][x] = true;

  if(cmd == 1) {
    long long val = solve(x + a[x], 2);
    if(val == -1) {
      memo[cmd][x] = -1;
    }
    else {
      memo[cmd][x] = val + a[x];
    }
  } else {
    long long val = solve(x - a[x], 1);
    if(val == -1) {
      memo[cmd][x] = -1;
    }
    else {
      memo[cmd][x] = val + a[x];
    }
  }
  return memo[cmd][x];
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n;

  for(int i = 2; i <= n; i++)
    cin >> a[i];

  memset(memo, 0, sizeof memo);
  memset(used, 0, sizeof used);

  memo[2][1] = 0;
  used[1][1] = true;

  for(int i = 1; i < n; i++) {
    long long val = solve(i + 1, 2);
    if(val == -1) cout << "-1" << endl;
    else cout << (val + i) << endl;
  }

  return 0;
}

