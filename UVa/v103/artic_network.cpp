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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

// Algorithm: MST - Kruskal

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

const int maxp = 510;

int x[maxp], y[maxp], p, s, pset[maxp], rank[maxp];
vector<Edge> roads;

void init(int n) {
    for(int i = 0; i < n; i++) {
        pset[i] = i; rank[i] = 0;
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
    }
    else {
        pset[py] = px;
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

    for(int e = 0; e < roads.size() && done < p - s; e++) {
        if(!same_set(roads[e].from, roads[e].to)) {
            unite(roads[e].from, roads[e].to);
            done++;

            ans = roads[e].cost;
        }
    }

    return ans;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &s, &p);

        roads.clear();

        REP(i, 0, p) {
            int a, b; scanf("%d%d", &a, &b);
            a--, b--;

            x[i] = a; y[i] = b;

            for(int j = i-1; j >= 0; j--) {
                double cost = hypot(double(x[i] - x[j]), double(y[i] - y[j]));
                roads.push_back( Edge(i, j, cost) );
            }
        }

        sort(ALL(roads));

        init(p);
        printf("%.2lf\n", kruskal());
    }
}

