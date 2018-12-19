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

#define INF 1<<30
#define EPS 1e-13

using namespace std;

int main() {
  int n, t;
  scanf("%d", &t);
  int cnt[10000+10];
  while(t--) {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    int maxval = -1, index;
    REP(i, n) {
      int a;
      scanf("%d", &a);
      cnt[a]++;
    }
    REP(i, 10000+10) if(cnt[i] > maxval) maxval = cnt[i], index = i;
    printf("%d %d\n", index, cnt[index]);
  }
}

