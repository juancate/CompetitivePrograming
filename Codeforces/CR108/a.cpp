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
  int n,m;
  cin >> n >> m;
  string data[n];
  bool st[n];
  memset(st, false, sizeof(st));

  REP(i,n) {
    cin >> data[i];
  }
  
  REP(j,m) {
    int p = 0;
    REP(i,n) {
      if(data[i][j] > data[p][j]) {
        p = i;
      }
    }
    REP(i,n) if(data[i][j] == data[p][j])
      st[i] = true;
  }
  int ans = 0;
  REP(i, n) {
    if(st[i]) ans++;
  }
  cout << ans << endl;
}

