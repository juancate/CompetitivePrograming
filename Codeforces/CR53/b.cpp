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

const int maxn = 100010;

int l[maxn], r[maxn], c[maxn];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  for(int i = 0; i < m; i++)
    cin >> l[i] >> r[i] >> c[i];

  long long ans = 0;
  for(int i = 0; i < k; i++) {
    int cell;
    cin >> cell;

    for(int j = 0; j < m; j++)
      if(l[j] <= cell && cell <= r[j]) {
        ans += (cell - l[j]) + c[j];
      }
  }

  cout << ans << endl;

  return 0;
}

