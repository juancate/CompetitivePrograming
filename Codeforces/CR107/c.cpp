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

typedef long long ll;

long long solve(long long q) {
  if(q == 1) return 0; 

  long long p = 2;
  vector<long long> factors;

  while(p <= q / p) {
    while(q % p == 0) {
      factors.push_back(p);
      q = q / p;
    }
    p++;
  }

  if(q != 1) factors.push_back(q);
  
  if(factors.size() == 1) return 0;
  if(factors.size() == 2) return -1;

  return factors[0] * factors[1];
}

int main() {
  long long q;
  cin >> q;
  int turn = 0;
  while(true) {
    long long p = solve(q);
    turn = !turn;
    if(p == -1) {
      cout << (turn + 1) << endl;
      if(!turn) cout << q << endl;
      break;
    } else if(p == 0) {
      cout << (!turn + 1) << endl;
      if(turn) cout << 0 << endl;
      break;
    }
    q = p;
  }
}

