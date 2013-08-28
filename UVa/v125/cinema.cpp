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
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxr = 27;
const int maxc = 110;

int r, c;
bool used[maxr][maxc];

const int maxn = 2610;

vector< vector<int> > G;
vector<bool> visited;
int owner[maxn];

int khun(int left) {
  if(visited[left]) return 0;

  visited[left] = true;

  for(int j = 0; j < (int)G[left].size(); j++) {
    int right = G[left][j];

    if(owner[right] == -1 || khun(owner[right])) {
      owner[right] = left;
      return 1;
    }
  }
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
#endif

  while(cin >> r >> c && (r|c)) {
    memset(used, false, sizeof(used));

    int z; cin >> z;

    REP(k, 0, z) {
      string pos, ind;
      cin >> pos >> ind;

      int i = pos[0] - 'A';
      int j = atoi(pos.substr(1).c_str()) - 1;

      if(ind[0] == '+') j++;

      used[i][j] = true;
    }

    int p; cin >> p;

    G.clear();
    G.resize(p);
    c++;

    REP(k, 0, p) {
      string pos; cin >> pos;
      int i = pos[0] - 'A';
      int j = atoi(pos.substr(1).c_str()) - 1;

      if(!used[i][j]) {
        G[k].push_back(i*c + j);
      }
      if(!used[i][j+1]) {
        G[k].push_back(i*c + j + 1);
      }
    }


    int card = 0;
    memset(owner, -1, sizeof(owner));

    REP(left, 0, p) {
      visited.assign(p, false);
      card += khun(left);
    }

    cout << ((card == p)? "YES" : "NO") << endl;
  }
}

