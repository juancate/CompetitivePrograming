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

int main() {
  ios_base::sync_with_stdio(false);
  vector<string> v;
  string s;

  while(getline(cin, s)) {
    v.push_back(s);
  }

  int n = v.size();
  int m = v[0].size();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(v[i][j] == '#') {
        bool ok = (j+1 < m && i+1 < n && v[i][j+1] == '#' && v[i+1][j+1] == '#' && v[i+1][j] == '#');
        ok |= (j-1 >= 0 && i+1 < n && v[i][j-1] == '#' && v[i+1][j-1] == '#' && v[i+1][j] == '#');
        ok |= (j+1 < m && i-1 >= 0 && v[i][j+1] == '#' && v[i-1][j+1] == '#' && v[i-1][j] == '#');
        ok |= (j-1 >= 0 && i-1 >= 0 && v[i][j-1] == '#' && v[i-1][j-1] == '#' && v[i-1][j] == '#');
        if(ok) {
          cout << "YES" << endl;
          return 0;
        }
      }
      else if(v[i][j] == '.') {
        v[i][j] = '#';

        bool ok = (j+1 < m && i+1 < n && v[i][j+1] == '#' && v[i+1][j+1] == '#' && v[i+1][j] == '#');
        ok |= (j-1 >= 0 && i+1 < n && v[i][j-1] == '#' && v[i+1][j-1] == '#' && v[i+1][j] == '#');
        ok |= (j+1 < m && i-1 >= 0 && v[i][j+1] == '#' && v[i-1][j+1] == '#' && v[i-1][j] == '#');
        ok |= (j-1 >= 0 && i-1 >= 0 && v[i][j-1] == '#' && v[i-1][j-1] == '#' && v[i-1][j] == '#');

        if(ok) {
          cout << "YES" << endl;
          return 0;
        }

        v[i][j] = '.';
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(v[i][j] == '.') {
        bool ok = (j+1 < m && i+1 < n && v[i][j+1] == '.' && v[i+1][j+1] == '.' && v[i+1][j] == '.');
        ok |= (j-1 >= 0 && i+1 < n && v[i][j-1] == '.' && v[i+1][j-1] == '.' && v[i+1][j] == '.');
        ok |= (j+1 < m && i-1 >= 0 && v[i][j+1] == '.' && v[i-1][j+1] == '.' && v[i-1][j] == '.');
        ok |= (j-1 >= 0 && i-1 >= 0 && v[i][j-1] == '.' && v[i-1][j-1] == '.' && v[i-1][j] == '.');
        if(ok) {
          cout << "YES" << endl;
          return 0;
        }
      }
      else if(v[i][j] == '#') {
        v[i][j] = '.';

        bool ok = (j+1 < m && i+1 < n && v[i][j+1] == '.' && v[i+1][j+1] == '.' && v[i+1][j] == '.');
        ok |= (j-1 >= 0 && i+1 < n && v[i][j-1] == '.' && v[i+1][j-1] == '.' && v[i+1][j] == '.');
        ok |= (j+1 < m && i-1 >= 0 && v[i][j+1] == '.' && v[i-1][j+1] == '.' && v[i-1][j] == '.');
        ok |= (j-1 >= 0 && i-1 >= 0 && v[i][j-1] == '.' && v[i-1][j-1] == '.' && v[i-1][j] == '.');

        if(ok) {
          cout << "YES" << endl;
          return 0;
        }

        v[i][j] = '#';
      }
    }
  }
  cout << "NO" << endl;

  return 0;
}

