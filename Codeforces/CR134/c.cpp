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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

struct obj {
    int x, y, node;
};

bool cmp_x(obj a, obj b) {
    return a.x < b.x;
}

bool cmp_y(obj a, obj b) {
    return a.y < b.y;
}

int n, nc;
vector<obj> points;

vector< vector<int> > G;

bool visited[111];

void dfs(int v) {
    if(visited[v]) return;
    visited[v] = true;

    for(int i = 0; i < n; i++) {
        if(points[i].x == points[v].x || points[i].y == points[v].y)
            dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    points.resize(n);
    G.resize(n);
    REP(i, 0, n)
        cin >> points[i].x >> points[i].y, points[i].node = i;

    nc = 0;

    memset(visited, false, sizeof(visited));

    REP(i, 0, n) {
        if(!visited[i]) {
            nc++;
            dfs(i);
        }
    }

    cout << (nc-1) << endl;
}

