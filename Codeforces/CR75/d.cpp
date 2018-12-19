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

  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  reverse(ALL(a));

  map<int, int> m;
  map<int, int>::iterator it;

  m[0] = 0;
  m[2000000000] = 0;
  vector<int> ans;

  for(int i = 0; i < n; i++) {
    it = m.lower_bound(a[i]);
    it--;
    int d = i - it->second - 1;
    if(it->first == 0 || it->first > a[i])
      d = -1;
    ans.push_back(d);

    it = m.begin();
    it++;
    if(a[i] < it->first) {
      m[a[i]] = i;
    }
  }
  for(int i = n-1; i >= 0; i--) {
    cout << ans[i];
    if(i) cout << ' ';
  }
  cout << endl;

  return 0;
}

