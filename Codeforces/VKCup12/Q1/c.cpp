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

int n;
vector<string> dirs;

void split(const string & s) {
  int m = s.size();
  string dir = "";
  REP(i,m) {
    if(s[i] == '/') {
      if(dir == "..") dirs.pop_back();
      else dirs.push_back(dir); // check whe just /
      dir = "";
    }
    else dir += s[i];
  }
  if(dir == "..") dirs.pop_back();
  else dirs.push_back(dir); // check whe just /
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  REP(i,n) {
    string cmd, path;
    cin >> cmd;
    if(cmd == "cd") {
      cin >> path;
      if(path[0] == '/') dirs.clear();
      split(path);
    }
    else {
      cout << '/';
      REP(i, dirs.size()) if(dirs[i] != "")
        cout << dirs[i] << '/';
      cout << '\n';
    }
  }
}

