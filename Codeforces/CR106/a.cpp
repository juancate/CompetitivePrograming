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

int main() {
  int k;
  cin >> k;
  int months[12];
  REP(i, 12) cin >> months[i];
  sort(months, months+12);
  int sum = 0, count = 0;
  for(int i = 11; i >= 0; i--) {
    sum += months[i];
    if(sum >= k) { count++; break; }
    else count++;
  }
  if(k == 0) cout << 0 << endl;
  else if(sum < k) cout << -1 << endl;
  else cout << count << endl;
}

