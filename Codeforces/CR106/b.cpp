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
string line;

int to_int(char n) {
  if(!isdigit(n)) return n - 'A' + 10;
  return n - '0';
}

int convert(string n, int base) {
  int ret = 0;
  int pot = 1;

  for(int i = n.size()-1; i >= 0; i--) {
    ret += to_int(n[i]) * pot;
    pot *= base;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  getline(cin, line);

  a = line.substr(0, line.find(":"));
  b = line.substr(line.find(":")+1);

  int base = 0;
  for(int i = 0; i < a.size(); i++) {
    base = max(base, to_int(a[i]));
  }

  for(int i = 0; i < b.size(); i++) {
    base = max(base, to_int(b[i]));
  }

  base++;
  vector<int> ans;
  bool valid = true;

  for(int i = base; i <= 100; i++) {
    if(convert(a, i) < 24 && convert(b, i) < 60) {
      ans.push_back(i);
    }
    else {
      valid = false;
      break;
    }
  }

  if(valid) cout << -1 << endl;
  else if(ans.empty()) cout << 0 << endl;
  else {
    for(int i = 0; i < ans.size(); i++) {
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}

