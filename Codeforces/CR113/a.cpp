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

bool comp(pair<int, int> a, pair<int, int> b) {
  if(a.first > b.first) return true;
  else if(a.first == b.first and a.second < b.second) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector< pair<int,int> > teams(n);
  REP(i,n) cin >> teams[i].first >> teams[i].second;
  sort(ALL(teams), comp);
  pair<int, int> pk = teams[k-1];
  int ans = 0;
  for(int i = k-1; i < n and teams[i] == pk; i++) ans++;
  for(int i = k-2; i >= 0 and teams[i] == pk; i--) ans++;
  cout << ans << endl;
}

