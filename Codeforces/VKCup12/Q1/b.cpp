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

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> groups(n);
  REP(i,n) cin >> groups[i];
  sort(ALL(groups));
  reverse(ALL(groups));
  int i = 0, j = n-1;
  int ans = 0;
  while(i <= j) {
    int sum = groups[i];
    while(i < j and sum + groups[j] <= 4) {
      sum += groups[j];
      j--;
    }
    ans++;
    i++;
  }
  cout << ans << endl;
}

