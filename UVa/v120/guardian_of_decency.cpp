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

const int maxn = 510;

struct person {
  int h, m, s;
} men[maxn], women[maxn];

vector<int> g[maxn];
map<string,int> mm, ms;

int owner[maxn];
bool used[maxn];

int khun(int left) {
  if(used[left]) return 0;
  used[left] = true;

  for(int i = 0; i < g[left].size(); i++) {
    int right = g[left][i];
    if(owner[right] == -1 || khun(owner[right])) {
      owner[right] = left;
      return 1;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    int n, m, w;
    cin >> n;
    m = w = 0;
    for(int i = 0; i < n; i++) {
      int h;
      char sex;
      string music, sport;
      cin >> h >> sex >> music >> sport;
      if(!mm.count(music))
        mm[music] = mm.size()-1;
      if(!ms.count(sport))
        ms[sport] = ms.size()-1;
      if(sex == 'M') {
        men[m].h = h;
        men[m].m = mm[music];
        men[m].s = ms[sport];
        m++;
      }
      else {
        women[w].h = h;
        women[w].m = mm[music];
        women[w].s = ms[sport];
        w++;
      }
    }

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < w; j++) {
        if(abs(men[i].h - women[j].h) <= 40 &&
           men[i].m == women[j].m && men[i].s != women[j].s)
          g[i].push_back(j);
      }
    }

    int card = 0;
    memset(owner, -1, sizeof owner);
    for(int left = 0; left < m; left++) {
      memset(used, 0, sizeof used);
      card += khun(left);
    }
    printf("%d\n", n-card);

    mm.clear();
    ms.clear();
    for(int i = 0; i < n; i++)
      g[i].clear();
  }
  return 0;
}

