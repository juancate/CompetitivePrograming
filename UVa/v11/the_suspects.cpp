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

int dsu[30010], rank[30010], size[30010];

void init(int n) {
    for(int i = 0; i < n; i++) {
        dsu[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
}

int find(int x) {
    return (x == dsu[x])? x : dsu[x] = find(dsu[x]);
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);

    if(px == py) return;

    if(rank[px] < rank[py]) {
        dsu[px] = py;
        size[py] += size[px];
    }
    else {
        dsu[py] = px;
        size[px] += size[py];
        if(rank[px] == rank[py])
            rank[px]++;
    }
}

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m)) {
        if((n|m) == 0) break;

        init(n);

        for(int i = 0; i < m; i++) {
            int k, x;
            scanf("%d", &k);

            if(k > 0) scanf("%d", &x);

            for(int j = 1; j < k; j++) {
                int y;
                scanf("%d", &y);
                unite(x, y);
            }
        }

        printf("%d\n", size[find(0)]);
    }
}

