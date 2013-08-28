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
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int a[32], b[32];

bool check() {
  for(int i = 0; i < 30; i++) {
    if(a[i] < b[i])
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  while(t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    for(int i = 0; i < 2; i++) {
      string s;
      cin >> s;
      for(int j = 0; j < s.size(); j++)
        a[s[j]-'a']++;
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for(int j = 0; j < s.size(); j++)
        b[s[j]-'a']++;
    }

    cout << (check()? "YES" : "NO") << endl;
  }

  return 0;
}

