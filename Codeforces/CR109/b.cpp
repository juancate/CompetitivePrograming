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

#define fs first
#define sc second
 
#define INF 1<<30
#define EPS 1e-13

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector< pair<int,int> > cards(n);
  REP(i,n) cin >> cards[i].sc >> cards[i].fs;
  sort(ALL(cards));
  reverse(ALL(cards));
  int count = 1, ans = 0;
  REP(i,n) {
    count--;
    ans += cards[i].sc;
    count += cards[i].fs;
    if(count == 0) break;
  }
  cout << ans << endl;
}

