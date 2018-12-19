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
  int n;
  cin >> n;

  vector<long long> a(n+1);

  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(++a.begin(), a.end());

  long long moves = 0;

  for(int i = 1; i <= n; i++) {
    long long d = (long long)i - a[i];
    if(d < 0) d = -d;
    moves += d;
  }
  cout << moves << endl;

  return 0;
}

