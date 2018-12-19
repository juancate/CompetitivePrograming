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
  string number;
  cin >> n >> number;

  sort(number.begin(), number.begin() + n);
  sort(number.begin() + n, number.end());

  bool ini = true, end = true;
  REP(i,n) ini &= number[i] > number[i+n];
  REP(i,n) end &= number[i] < number[i+n];

  if(ini or end) cout << "YES" << endl;
  else cout << "NO" << endl;
}

