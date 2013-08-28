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

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<string> b(n, string(n, ' ')), orig;
  for(int i = 0; i < n; i++)
    cin >> b[i];

  orig = b;

  int p = n*n;
  for(int run = 1; run < k; run++) {
    vector<string> next(p, string(p, ' '));
    int m = orig.size();
    int a = b.size();

    for(int i = 0; i < a; i++) {
      for(int j = 0; j < a; j++) {
        if(b[i][j] == '*') {
          for(int r = i*m; r < i*m+m; r++)
            for(int s = j*m; s < j*m+m; s++)
              next[r][s] = '*';
        }
        else {
          for(int r = i*m, u = 0; r < i*m+m; r++, u++)
            for(int s = j*m, v = 0; s < j*m+m; s++, v++)
              next[r][s] = orig[u][v];
        }
      }
    }

    p *= n;
    b = next;
  }

  for(int i = 0; i < b.size(); i++)
    cout << b[i] << endl;

  return 0;
}

