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

set<long long> lucky;

void gen(string s) {
  if(s.size() > 10)
    return;

  long long a = strtoll(s.c_str(), 0, 10);
  if(!lucky.count(a)) {
    lucky.insert(a);

    gen(s + "4");
    gen(s + "7");
    gen("4" + s);
    gen("7" + s);
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  gen("4");
  gen("7");

  vector<long long> v(ALL(lucky));

  int l, r;
  cin >> l >> r;

  int i = int(lower_bound(ALL(v), l) - v.begin());
  long long sum = 0;
  for(; i < v.size(); i++) {
    if(r > v[i]) {
      sum += (v[i] - l + 1) * v[i];
      l = v[i]+1;
    }
    else {
      sum += (r - l + 1) * v[i];
      break;
    }
  }

  cout << sum << endl;

  return 0;
}

