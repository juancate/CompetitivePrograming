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

set<int> parse(string s) {
  int n = s.size();
  set<int> r;

  for(int i = 0; i < n; i++) {
    string x;
    while(i < n && s[i] != ',')
      x.push_back(s[i++]);
    r.insert(atoi(x.c_str()));
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  getline(cin, s);

  set<int> nums = parse(s);
  vector<int> v(ALL(nums));

  int n = v.size();
  for(int i = 0; i < n; i++) {
    if(i) cout << ",";
    int l = i, r = i;
    while(r + 1 < n && v[r]+1 == v[r+1]) {
      r++;
    }
    i = r;
    cout << v[l];
    if(l != r)
      cout << "-" << v[r];
  }
  cout << endl;

  return 0;
}

