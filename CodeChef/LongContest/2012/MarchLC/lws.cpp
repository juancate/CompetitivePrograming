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

using namespace std;

const int MAXN = 2000 + 10;

int memo[MAXN][27][27];
string word;

int lws(int i, int j, int k) {
  if(i >= n) return 0;
  int & ret = memo[i][j][k];
  if(ret != -1) return ret;

  int ans = 0;
  if(word[i] <= 'a'+j) ans = lws(i+1, j+1, k) + 1;
  else if(word[i] >= 'a'+k) ans = lws(i+1, j, k+1) + 1;
  else ans = max(lws(i,j+1,k), lws(i,j,k+1));
  
  return ret = ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    char line[MAXN];
    scanf("%s", line);
    word = line;
    int ans = lws(0, 0, 0);
    printf("%d\n", ans);
  }
}

