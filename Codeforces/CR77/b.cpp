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
  string sn;
  cin >> sn;

  long long n = atoll(sn.c_str());
  int m = sn.size();

  if(m & 1) m++;

  string ans(m, ' ');
  for(int i = 0; 2*i < m; i++)
    ans[i] = '7';

  for(int i = m/2; i < m; i++)
    ans[i] = '4';

  if(n > atoll(ans.c_str())) {
    ans = string(1, '7') + ans + string(1, '4');
  }
  sort(ALL(ans));

  long long best = INFLL;

  do {
    long long curr = atoll(ans.c_str());
    if(curr < n) continue;
    best = min(best, curr);
  } while(next_permutation(ALL(ans)));

  cout << best << endl;

  return 0;
}

