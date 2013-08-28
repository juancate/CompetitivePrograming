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

int whatis(string& s) {
  bool taxi, pizza;
  taxi = pizza = true;
  for(int i = 1; i < s.size(); i++) {
    if(s[i] == '-') continue;
    if(s[i-1] == '-') {
      if(s[i] != s[i-2]) taxi = false;
      if(s[i] >= s[i-2]) pizza = false;
    } else {
      if(s[i] != s[i-1]) taxi = false;
      if(s[i] >= s[i-1]) pizza = false;
    }
  }
  if(taxi) return 0;
  if(pizza) return 1;
  return 2;
}

int main() {
  int n;
  cin >> n;
  int tpg[3][n];
  memset(tpg, 0, sizeof(tpg));
  string names[n];
  vector<string> mtpg[3];
  REP(k, n) {
    int si;
    string name;
    cin >> si >> names[k];
    REP(i, si) {
      string number;
      cin >> number;
      tpg[whatis(number)][k]++;
    }
  }

  int maxval = -1;
  REP(i, n) maxval = max(maxval, tpg[0][i]);

  REP(i, n) if(maxval == tpg[0][i]) mtpg[0].push_back(names[i]);

  maxval = -1;

  REP(i, n) maxval = max(maxval, tpg[1][i]);

  REP(i, n) if(maxval == tpg[1][i]) mtpg[1].push_back(names[i]);

  maxval = -1;
  REP(i, n) maxval = max(maxval, tpg[2][i]);

  REP(i, n) if(maxval == tpg[2][i]) mtpg[2].push_back(names[i]);

  cout << "If you want to call a taxi, you should call: ";
  REP(i, mtpg[0].size()) { 
    if(i) cout << ", "; 
    cout << mtpg[0][i];
  }
  cout << ".\n";

  cout << "If you want to order a pizza, you should call: ";
  REP(i, mtpg[1].size()) { 
    if(i) cout << ", "; 
    cout << mtpg[1][i];
  }
  cout << ".\n";

  cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
  REP(i, mtpg[2].size()) { 
    if(i) cout << ", "; 
    cout << mtpg[2][i];
  }
  cout << ".\n";
}

