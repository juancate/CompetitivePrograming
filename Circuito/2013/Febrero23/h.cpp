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

typedef pair<int, int> ii;
typedef pair<double, ii> Edge;

#define Edge(a, b, c) make_pair(c, make_pair(a, b))
#define cost first
#define from second.first
#define to second.second

const int maxn = 1010;

int x[maxn], y[maxn], min_y[maxn], N, pset[maxn], rank[maxn];
vector<Edge> roads;

void init(int n) {
  for(int i = 0; i < n; i++) {
    pset[i] = i;
    rank[i] = 0;
    min_y[i] = y[i];
  }
}

int find(int x) {
  return (pset[x] == x)? x : pset[x] = find(pset[x]);
}

void unite(int x, int y) {
  int px = find(x);
  int py = find(y);

  if(px == py)
    return;

  if(rank[px] < rank[py]) {
    pset[px] = py;
    min_y[py] = min(min_y[px], min_y[py]);
  }
  else {
    pset[py] = px;
    min_y[px] = min(min_y[py], min_y[px]);
    if(rank[px] == rank[py])
      rank[px]++;
  }
}

bool same_set(int x, int y) {
  return find(x) == find(y);
}

double kruskal() {
  int done = 0;
  double ans = 0;

  for(int e = 0; e < roads.size() && done < N; e++) {
    int a = roads[e].from;
    int b = roads[e].to;

    if(!same_set(a, b)) {

      bool ok = false;
      bool ok_a = y[a] == min_y[find(a)];
      bool ok_b = y[b] == min_y[find(b)];

      if(y[a] > y[b]) {
        ok = ok_a;
      }
      else if(y[a] < y[b]) {
        ok = ok_b;
      }
      else {
        ok = ok_a || ok_b;
      }

      if(ok) {
        unite(a, b);
        done++;

        ans += roads[e].cost;
      }
    }
  }

  return ans;
}


int main() {
  while(scanf("%d", &N)) {
    if(!N) break;

    roads.clear();

    for(int i = 0; i < N; i++) {
      scanf("%d%d", &x[i], &y[i]);
      for(int j = 0; j < i; j++) {
        roads.push_back(Edge(i, j, hypot(double(x[i]-x[j]), double(y[i]-y[j]))));
      }
    }

    sort(roads.begin(), roads.end());

    init(N);
    double ans = kruskal();
    printf("%.2lf\n", ans);
  }
}
