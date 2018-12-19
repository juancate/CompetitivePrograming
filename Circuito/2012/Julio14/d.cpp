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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

typedef pair<int, int> ii;

int f, s, g, u, d;

int bfs() {
    bool visited[f+1];
    memset(visited, false, sizeof(visited));

    queue<ii> Q;
    Q.push( ii(s, 0) );
    visited[s] = true;

    while(!Q.empty()) {
        int current = Q.front().first;
        int cost = Q.front().second;
        Q.pop();

        if(current == g) return cost;

        if(current + u <= f && !visited[current + u]) {
            Q.push( ii(current + u, cost + 1) );
            visited[current + u] = true;
        }

        if(current - d >= 1 && !visited[current - d]) {
            Q.push( ii(current - d, cost + 1) );
            visited[current - d] = true;
        }
    }

    return -1;
}

int main() {
    while(~scanf("%d%d%d%d%d", &f, &s, &g, &u, &d) && (f|s|g|u|d)) {
        int ans = bfs();

        if(ans < 0) puts("use the stairs");
        else printf("%d\n", ans);
    }
}

