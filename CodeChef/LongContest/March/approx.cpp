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

char* pi = "31415926530119026040722614947737296840070086399613316";
char ans[1000010];

int main() {
  int t, k;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &k);
    int i = 0, j = 0;
    k++;
    while(k--) {
      ans[j++] = pi[i];
      if(!i && k) ans[j++] = '.';
      i++;
      if(i == 53) i = 2;
    }
    ans[j] = 0;
    puts(ans);
  }
  return 0;
}

