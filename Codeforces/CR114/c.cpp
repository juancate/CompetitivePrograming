#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define INF 1<<30
#define EPS 1e-13

using namespace std;

int n, a, d;
const int MAXN = 100000 + 5;

double answer[MAXN];

double solve(int s) {
  double t = (double)s / (double)a;
  double x = a * t * t * 0.5;

  if(d <= x)
    return sqrt(2.0 * d / a);
  return t + (d - x) / s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> d;
  double last = 0.0;
  REP(i,n) {
    int spent, speed;
    cin >> spent >> speed;
    double t = solve(speed) + spent;
    last = answer[i] = max(t, last);
  }
  REP(i,n) cout << answer[i] << endl;
}

