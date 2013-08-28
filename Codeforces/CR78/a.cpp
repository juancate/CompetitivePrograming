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
  string ln, a, b;
  cin >> ln;

  int pos = ln.find(".");
  a = ln.substr(0, pos);
  b = ln.substr(pos+1);

  if(a[a.size()-1] == '9') {
    cout << "GOTO Vasilisa." << endl;
  }
  else {
    if(b[0] < '5') {
      cout << a << endl;
    }
    else {
      a[a.size()-1]++;
      cout << a << endl;
    }
  }

  return 0;
}

