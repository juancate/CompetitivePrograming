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

set< pair<int, pair<int,int> > > seen;

int bfs(int sx, int sy, int ex, int ey, string w) {
  map<char,int> x, y;
  x['E'] = 1, x['W'] = -1;
  y['N'] = 1, y['S'] = -1;

  queue< pair<int, pair<int,int> >  > q;
  q.push( make_pair(0, make_pair(sx, sy)) );
  seen.insert( make_pair(0, make_pair(sx, sy)) );

  while(!q.empty()) {
    pair< int, pair<int,int> > curr = q.front();
    q.pop();

    int t = curr.first;
    int currx = curr.second.first;
    int curry = curr.second.second;

    if(currx == ex && curry == ey)
      return t;

    pair< int, pair<int,int> > next = make_pair(t+1, make_pair(currx, curry));
    int d = abs(currx - ex) + abs(curry - ey);
    if(t+d+1 <= w.size() && !seen.count(next)) {
      q.push(next);
      seen.insert(next);
    }

    currx += x[w[t]];
    curry += y[w[t]];
    next = make_pair(t+1, make_pair(currx, curry));
    d = abs(currx - ex) + abs(curry - ey);

    if(t+d+1 <= w.size() && !seen.count(next)) {
      q.push(next);
      seen.insert(next);
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);


  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;

  string w;
  cin >> w;

  int d = abs(sx - ex) + abs(sy - ey);

  if(d > t) {
    cout << -1 << endl;
  }
  else {
    cout << bfs(sx, sy, ex, ey, w) << endl;
  }

  return 0;
}

