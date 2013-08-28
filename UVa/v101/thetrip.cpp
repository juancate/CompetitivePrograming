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
#include <climits>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

const int INF = 1000000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n) == 1 and n != 0) {
    vector<double> money(n);
    double avg = 0.0;
    REP(i,n) {
      scanf("%lf", &money[i]);
      avg += money[i];
    }

    avg = avg / (double)n;
    avg = floor(avg*100. + .5) / 100.;

    double ans = 0, least = 0;
    REP(i,n) {
      double diff = avg - money[i];
      if(diff > EPS) ans += diff;
      else least += (-diff);
    }
    ans = min(ans, least);
    printf("$%.2lf\n", ans);
  }
}

