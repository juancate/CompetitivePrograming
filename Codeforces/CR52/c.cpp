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
#define foreach(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

struct node {
  multiset<string> sons;
  int ans;
  node() {
    ans = 0;
    sons = multiset<string>();
  }
};

string expr;
int pos;

node solve() {
  string name = "";
  node n;

  while(isalpha(expr[pos]))
    name += expr[pos++];

  while(expr[pos] == ',' || expr[pos] == ':') {
    pos++;
    node curr = solve();
    n.ans += curr.ans;
    n.ans += curr.sons.count(name);

    foreach(v, curr.sons)
      n.sons.insert(*v);
  }

  pos++;
  n.sons.insert(name);
  return n;
}

int main() {
  ios_base::sync_with_stdio(false);

  getline(cin, expr);
  pos = 0;

  node r = solve();
  cout << r.ans << endl;

  return 0;
}

