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

const int MAXN = 1000 + 10;

struct state {
    int r, c, type, cost;

    state(int s = 0, int rows = 0, int cols = 0, int t = 0) :
        cost(s), r(rows), c(cols), type(t) {}
};

typedef pair<int,int> ii;
#define mp make_pair

int R, C;
char board[MAXN][MAXN];
bool visited[MAXN][MAXN];

int head, tail;
state Q[MAXN * MAXN];

bool valid(int nr, int nc) {
    return (nr >= 0 && nr < R && nc >= 0 && nc < C);
}

int bfs() {

    while(head < tail) {
        const state& s = Q[head++];

        if(s.type == 0 && board[s.r][s.c] == 'F')
            continue;

        int sr = 0, sc = 1;

        REP(k, 0, 4) {
            int nr = s.r + sr;
            int nc = s.c + sc;

            if(s.type == 0) {
                if(valid(nr, nc) && !visited[nr][nc] && board[nr][nc] == '.') {
                    Q[tail].cost = s.cost + 1;
                    Q[tail].r = nr, Q[tail].c = nc, Q[tail++].type = s.type;
                    visited[nr][nc] = true;
                } else if(nr < 0 || nr >= R || nc < 0 || nc >= C) {
                    return s.cost + 1;
                }
            } else {
                if(valid(nr, nc) && board[nr][nc] != '#' && board[nr][nc] != 'F') {
                    Q[tail].cost = s.cost + 1;
                    Q[tail].r = nr, Q[tail].c = nc, Q[tail++].type = s.type;
                    board[nr][nc] = 'F';
                }
            }
            int tmp = sr;
            sr = -sc, sc = tmp;
        }
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d\n", &R, &C);

        head = tail = 0;

        REP(i, 0, R) {
            gets(board[i]);
            REP(j, 0, C) {
                visited[i][j] = false;
                if(board[i][j] == 'J') {
                    Q[tail].cost = 0, Q[tail].r = i, Q[tail].c = j, Q[tail++].type = 0;
                    visited[i][j] = true;
                } else if(board[i][j] == 'F') {
                    Q[tail].cost = 0, Q[tail].r = i, Q[tail].c = j, Q[tail++].type = 1;
                    visited[i][j] = true;
                }
            }
        }

        int ans = bfs();

        if(ans < 0) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
}

