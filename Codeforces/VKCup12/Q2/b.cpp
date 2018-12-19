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

typedef pair<int,int> ii;

const int MAXN = 1000;

int markers[MAXN+10][MAXN+10];
int cnt[MAXN+10];

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  memset(markers, false, sizeof(markers));
  memset(cnt, 0, sizeof(cnt));

  int closed = 0, beauty = 0;
  REP(i,n) {
    int a, b;
    cin >> a >> b;
    markers[a][b]++;
    cnt[b]++;
  }
  vector<ii> caps;
  REP(i,m) {
    int x, y;
    cin >> x >> y;
    if(markers[x][y] > 0) {
      closed++; beauty++;
      markers[x][y]--;
      cnt[y]--;
    } else {
      caps.push_back(ii(x,y));
    }
  }

  REP(i, caps.size()) {
    int y = caps[i].second;
    if(cnt[y] > 0) {
      closed++;
      cnt[y]--;
    }
  }

  cout << closed << ' ' << beauty << '\n';
}

