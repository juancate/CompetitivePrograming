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
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const double PI = acos(-1.0);

inline double deg_to_rad(double theta) {
  return theta * PI / 180.;
}

int main() {
  int l, w, h, a;
  while(~scanf("%d%d%d%d", &l, &w, &h, &a)) {
    double thetha = deg_to_rad(a);
    double op1 = l * sin(thetha);
    double adj1 = l * cos(thetha);
    double op2 = op1 * tan(thetha);

    double bt = adj1 + op2;
    double ht = op1;

    double A = bt * ht * .5;
    double V = A * w;

    double Vt = l * w * h;

    printf("%.3lf mL\n", Vt - V);
  }

  return 0;
}

