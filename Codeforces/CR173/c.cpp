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

string a, b;
bool can[1000010];

void op(int i, int j, char& x, char& o) {
  if(a[i] == a[j]) {
    x = '0';
    o = a[i];
  }
  else {
    x = '1';
    o = (a[i] == '1' || a[j] == '1')? '1' : '0';
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> a >> b;
  memset(can, false, sizeof can);

  if(a.size() != b.size()) {
    cout << "NO" << endl;
    return 0;
  }
  int n = a.size();
  string tmp = a;

  for(int i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      char x, o;
      if(i < n-1) {
        if(can[i+1]) {
          can[i] = true;
          continue;
        }

        op(i, i+1, x, o);
        if(a[i] != x || a[i] != o)
          can[i] = true;
      }
      if(i > 0) {
        if(can[i-1]) {
          can[i] = true;
          continue;
        }
        op(i-1, i, x, o);
        if(a[i] != x | a[i] != o)
          can[i] = true;
      }
    }
    if(i > 0 && can[i-1]) can[i] = true;
    if(i < n-1 && can[i+1]) can[i] = true;
  }

  for(int i = n-1; i >= 0; i--) {
    if(a[i] != b[i]) {
      char x, o;
      if(i < n-1) {
        if(can[i+1]) {
          can[i] = true;
          continue;
        }

        op(i, i+1, x, o);
        if(a[i] != x || a[i] != o)
          can[i] = true;
      }
      if(i > 0) {
        if(can[i-1]) {
          can[i] = true;
          continue;
        }
        op(i-1, i, x, o);
        if(a[i] != x | a[i] != o)
          can[i] = true;
      }
    }
    if(i > 0 && can[i-1]) can[i] = true;
    if(i < n-1 && can[i+1]) can[i] = true;
  }

  for(int i = 0; i < n; i++) {
    if(a[i] != b[i] && !can[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}

