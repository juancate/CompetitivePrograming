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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 111;

int board[maxn][maxn], n, m;
bool visited[maxn][maxn];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

struct node {
    int r, c, cost;
    node(int row, int col, int cost_) {
        r = row, c = col, cost = cost_;
    }
};

bool valid(int nr, int nc) {
    return (nr >= 0 && nr <= n-1 && nc >= 0 && nc <= m-1);
}

int bfs(int row_start, int col_start, int row_end, int col_end) {
    memset(visited, false, sizeof(visited));

    queue< node > Q;
    Q.push( node(row_start, col_start, 1) );

    visited[row_start][col_start] = true;

    while(!Q.empty()) {
        node current = Q.front();
        Q.pop();

        if(current.r == row_end && current.c == col_end)
            return current.cost;

        for(int k = 0; k < 4; k++) {
            int nr = current.r + dr[k];
            int nc = current.c + dc[k];

            if(valid(nr, nc) && board[nr][nc] == 0 && !visited[nr][nc]) {
                Q.push( node(nr, nc, current.cost + 1) );
                visited[nr][nc] = true;
            }
        }
    }

    return -1;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &m, &n);

        REP(i, 0, n) REP(j, 0, m) scanf("%d", &board[i][j]);

        int row_start, col_start, row_end, col_end;
        scanf("%d%d", &col_start, &row_start);
        scanf("%d%d", &col_end, &row_end);

        printf("%d\n", bfs(row_start, col_start, row_end, col_end));
    }
}

