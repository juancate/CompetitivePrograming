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
  ios_base::sync_with_stdio(false);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  if(c == 0 || e == 0) {
    cout << "Ron\n";
    return 0;
  }

  int start = a * 1000;
  D(start);
  start = b * 1000;
  D(start);
  start = (start / c) * d;
  D(start);
  start = (start / e) * f;
  D(start);

  if(start <= a) cout << "Hermione\n";
  else cout << "Ron\n";

  return 0;
}

