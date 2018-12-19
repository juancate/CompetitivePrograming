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

// Algorithm: Bipartite matching

const int maxn = 550;

int n, m, e, owner[maxn];
pair<int,int> cats[maxn], dogs[maxn];
bool used[maxn];
vector<int> g[maxn];

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
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d\n", &n, &m, &e);

    int cat = 0, dog = 0;

    for(int i = 0; i < e; i++) {
      int a, b;
      char c, d;
      scanf("%c%d %c%d\n", &c, &a, &d, &b);
      if(c == 'C') {
        cats[cat++] = make_pair(a-1, b-1);
      }
      else {
        dogs[dog++] = make_pair(a-1, b-1);
      }
    }

    for(int i = 0; i < cat; i++) {
      for(int j = 0; j < dog; j++) {
        if(cats[i].first == dogs[j].second ||
           cats[i].second == dogs[j].first) {
          g[i].push_back(j+cat);
        }
      }
    }
    int card = 0;
    memset(owner, -1, sizeof owner);
    for(int left = 0; left < cat; left++) {
      memset(used, 0, sizeof used);
      card += khun(left);
    }
    printf("%d\n", e-card);

    for(int i = 0; i < cat+dog; i++)
      g[i].clear();
  }
  return 0;
}

