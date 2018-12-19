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

#define x first
#define y second

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector< pair<int, int> > points(n);
  REP(i,n) cin >> points[i].x >> points[i].y;
  sort(ALL(points));

  int cnt = 0;

  REP(i,n) {
    vector<bool> neigh(4, false);

    REP(j,n) {
      if(i == j) continue;
      if(points[j].x > points[i].x and points[j].y == points[i].y) neigh[0] = true;
      else if(points[j].x < points[i].x and points[j].y == points[i].y) neigh[1] = true;
      else if(points[j].x == points[i].x) {
        if(points[j].y < points[i].y) neigh[2] = true;
        else if(points[j].y > points[i].y) neigh[3] = true;
      }
      if(neigh[0] and neigh[1] and neigh[2] and neigh[3]) break;
    }
    if(neigh[0] and neigh[1] and neigh[2] and neigh[3]) cnt++;
  }

  cout << cnt << endl;
}

