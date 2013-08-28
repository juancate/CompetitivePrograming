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
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int minv, maxv;
  int scores[n];
  REP(i,n) cin >> scores[i];
  minv = maxv = scores[0];
  int ans = 0;
  for(int i = 1; i < n; i++) {
    if(minv > scores[i]) {
      ans++, minv = scores[i];
    } else if(maxv < scores[i]) {
      ans++, maxv = scores[i];
    }
  }
  cout << ans << endl;
}

