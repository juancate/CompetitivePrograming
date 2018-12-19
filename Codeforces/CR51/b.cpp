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

long long best;

void solve(vector<long long> a, int l, string op) {
  if(a.size() == 1) {
    best = min(best, a[0]);
    return;
  }
  int n = a.size();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      long long curr = a[i];
      if(op[l] == '+')
        curr += a[j];
      else
        curr *= a[j];
      vector<long long> b;
      b.push_back(curr);
      for(int k = 0; k < n; k++)
        if(k != i && k != j)
          b.push_back(a[k]);
      solve(b, l+1, op);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  vector<long long> a(4);
  for(int i = 0; i < 4; i++)
    cin >> a[i];
  string op;
  for(int i = 0; i < 3; i++) {
    char ch;
    cin >> ch;
    op.push_back(ch);
  }

  best = INFLL;
  solve(a, 0, op);

  cout << best << "\n";

  return 0;
}

