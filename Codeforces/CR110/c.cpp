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

const int MAXN = 2000;

int main() {
  ios_base::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b;
  c.assign(b.size()-1, '$');
  a = c+a+c;
  int n = a.length();
  int m = b.length();
  int best = INF;

  for(int i = 0; i <= n-m; i++) {
    int count = 0;
    for(int j = 0; j < m; j++) 
      if(a[i+j] != b[j]) count++;
    best = min(best, count);
  }

  cout << best << endl;
}

