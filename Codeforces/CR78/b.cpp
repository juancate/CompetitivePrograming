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

vector<int> cups, ord;
vector< pair<int,int> > data;

bool check() {
  int prev = cups[ord[0]];
  for(int i = 0; i < cups.size(); i++)
    if(cups[ord[i]] != prev)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, i, j;

  cin >> n;

  cups.resize(n);
  ord.resize(n);
  data.resize(n);

  for(i = 0; i < n; i++) {
    cin >> cups[i];
    data[i] = make_pair(cups[i], i);
  }

  sort(ALL(data));
  for(i = 0; i < n; i++)
    ord[i] = data[i].second;

  if(check()) {
    cout << "Exemplary pages." << endl;
    return 0;
  }

  vector<string> ans;
  i = 0; j = n-1;
  while(i < j) {
    int diff = cups[ord[j]] - cups[ord[i]];
    if(diff > 0) {
      diff >>= 1;
      stringstream ss;
      ss << diff << " ml. from cup #" << (ord[i]+1) << " to cup #" << (ord[j]+1) << ".";
      ans.push_back(ss.str());
      cups[ord[i]] += diff;
      cups[ord[j]] -= diff;
    }
    i++; j--;
  }

  if(!check() || ans.size() > 1) {
    cout << "Unrecoverable configuration." << endl;
  }
  else {
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i] << endl;
  }

  return 0;
}

