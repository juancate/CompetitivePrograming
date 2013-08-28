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

vector<int> votes;
vector<bool> calculated;
vector< vector<int> > sums;
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  votes.resize(n);
  calculated.resize(n, false);
  sums.resize(n);
  REP(i,n) cin >> votes[i];

  for(int d = 3; d <= n; d++) {
    int div = n / d;
    if(n % d == 0) {
      if(!calculated[div]) {
        for(int i = 0; i < div; i++) {
          int sum = 0;
          for(int j = i; j < n; j+=div) {
            sum += votes[j];
          }
          sums[div].push_back(sum);
        }
        calculated[div] = true;
      }
      if(div % 2 != 0) continue; // skip if next step can't be done
      vector<int> & s = sums[div];
      REP(i, s.size()) {
        int sum = s[i];
        if(i+1 == s.size()) sum += s[0];
        else sum += s[i+1];
        sums[div/2].push_back(sum);
      }
      calculated[div/2] = true;
    }
  }
  int ans = -INF;

  FOREACH(v, sums) {
    FOREACH(it, *v) {
      ans = max(ans, *it);
      cerr << *it << " ";
    }
    cerr << "\n";
  }

  cout << ans << endl;
}

