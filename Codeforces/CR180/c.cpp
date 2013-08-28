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

string a, b;
set<string> seen;

int count_ones(string s) {
  int r = 0;
  for(int i = 0; i < s.size(); i++)
    r += s[i] == '1';

  return r;
}

int parity(string s) {
  return (count_ones(s) & 1) != 0;
}

bool solve() {
  if(parity(a) + count_ones(a) >= count_ones(b))
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> a >> b;
  cout << (solve()? "YES\n" : "NO\n");

  return 0;
}

