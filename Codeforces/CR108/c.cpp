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

const long long mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  set<char> letters[m];

  REP(i,n) {
    string name;
    cin >> name;
    REP(j, m) {
      letters[j].insert(name[j]);
    }
  }

  long long ans = 1;
  REP(i,n) ans = ans * letters[i].size() % mod;
  cout << ans << endl;
}

