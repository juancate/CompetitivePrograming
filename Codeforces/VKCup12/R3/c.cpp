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
  a.push_back(0);

  vector< pair<int,int> > ans;
  stack<int> s;

  int inc = 0;

  for(int i = 0; i < a.size(); i++) {
    if(a[i] == a[i-1]) continue;

    while(!s.empty() && inc > a[i]) {
      ans.push_back(make_pair(s.top(), i-1));
      s.pop();
      inc--;
    }
    for(int j = 0; j + inc < a[i]; j++)
      s.push(i);
    inc = a[i];
  }

  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i].first+1 << " " << ans[i].second+1 << endl;

  return 0;
}

