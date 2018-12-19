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

string to_str(int x) {
  stringstream ss;
  if(x < 10) ss << 0;
  ss << x;
  return ss.str();
}

void print(int hh, int mm) {
  if(hh < 10) cout << 0;
  cout << hh << ':';
  if(mm < 10) cout << 0;
  cout << mm << endl;
}

int main() {
  ios_base::sync_with_stdio(false);

  string t;
  cin >> t;

  int a, b;
  a = atoi(t.substr(0, t.find(":")).c_str());
  b = atoi(t.substr(t.find(":")+1).c_str());

  for(int i = b+1; i < 60; i++) {
    string smm = to_str(i);
    reverse(ALL(smm));
    if(to_str(a) == smm) {
      print(a, i);
      return 0;
    }
  }

  int hh = (a+1) % 24;
  for(int i = 0; i < 24; i++) {
    int mm = 0;
    string shh = to_str(hh);
    for(int j = 0; j < 60; j++) {
      string smm = to_str(mm);
      reverse(ALL(smm));
      if(shh == smm) {
        print(hh, mm);
        return 0;
      }
      mm = (mm+1) % 60;
    }
    hh = (hh+1) % 24;
  }

  return 0;
}

