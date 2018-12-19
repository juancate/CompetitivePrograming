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

int s[256];
char _s[110];

int main() {
  int t;
  scanf("%d%s", &t, _s);

  for(int i = 0; i < 256; i++)
    s[i] = i;

  for(int i = 0; _s[i]; i++) {
    s['a'+i] = _s[i];
    s['A'+i] = 'A' + (_s[i] - 'a');
  }
  s['_'] = ' ';

  while(t--) {
    scanf("%s", _s);
    for(int i = 0; _s[i]; i++)
      printf("%c", s[_s[i]]);
    printf("\n");
  }

  return 0;
}

