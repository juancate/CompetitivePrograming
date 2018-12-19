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
#define PI 3.141592653589793

using namespace std;

int n;
vector<int> rs;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  rs.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> rs[i];
  }
  sort(ALL(rs));
  reverse(ALL(rs));

  double ans = 0.0;
  for(int i = 0; i < n; i+= 2) {
    double prev = (i+1 >= n)? 0.0 : PI*rs[i+1]*rs[i+1];
    ans = ans + (PI*rs[i]*rs[i] - prev);
  }
  cout << ans << endl;
}

