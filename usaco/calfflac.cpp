/*
ID: jcamarg1
PROG: calfflac
LANG: C++
*/
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

char s[20010], _line[20010];
int a[20010], sz;
string line;

void clean() {
  sz = 0;
  for(int i = 0; i < line.size(); i++) {
    if(isalpha(line[i])) {
      s[sz] = tolower(line[i]);
      a[sz++] = i;
    }
  }
}

bool is_pal(int i, int j) {
  while(i < j) {
    if(s[i++] != s[j--]) return false;
  }
  return true;
}

int main() {
  freopen("calfflac.in", "r", stdin);
  freopen("calfflac.out", "w", stdout);

  stringstream ss;
  while(fgets(_line, sizeof line, stdin)) {
    ss << _line;
  }
  line = ss.str();

  clean();
  int best = 0, l, r;

  for(int i = 0; i < sz; i++) {
    for(int j = i+2000-1; j >= 0; j--) {
      if(j-i+1 < best) break;
      if(is_pal(i, j)) {
        if(j-i+1 > best) {
          best = j-i+1;
          l = a[i]; r = a[j];
        }
        break;
      }
    }
  }

  printf("%d\n", best);
  for(int i = l; i <= r; i++) {
    printf("%c", line[i]);
  }
  printf("\n");

  return 0;
}

