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

#define mp make_pair

struct state {
    set< pair<int, int> > fire;
    int r, c, x, y, steps;

    state(int s = 0, int rows = 0, int cols = 0) : steps(s), r(rows), c(cols)
    {
    }
} start;

bool visited[MAXN][MAXN];
char board[MAXN][MAXN];

bool valid(int nr, int nc, int r, int c) {
    return (nr >= 0 && nr < r && nc >= 0 && nc < c && !visited[nr][nc]);
}

int bfs() {
    queue<state> Q;
    memset(visited, false, sizeof(visited));

    Q.push(start);
    visited[start.x][start.y] = true;

    while(!Q.empty()) {
        state s = Q.front();
        Q.pop();

        int sr = 0, sc = 1;
        REP(k, 0, 4) {
            int nr = s.x + sr;
            int nc = s.y + sc;
            int tmp = 0;

            if(valid(nr, nc, s.r, s.c) && board[nr][nc] == '.' && !s.fire.count( mp(nr, nc) )) {
                state next(s.steps + 1, s.r, s.c);
                next.x = nr, next.y = nc;

                bool ok = true;

                next.fire.insert(ALL(s.fire));

                FOREACH(it, s.fire) {
                    int ssr = 0, ssc = 1;
                    REP(m, 0, 4) {
                        int nnr = it->first + ssr;
                        int nnc = it->second + ssc;

                        if(nnr == nr && nnc == nc) {
                            ok = false;
                            break;
                        }

                        if(valid(nnr, nnc, s.r, s.c) && board[nnr][nnc] != '#') {
                            next.fire.insert( mp(nnr, nnc) );
                        }
                        tmp = ssr;
                        ssr = -ssc, ssc = tmp;
                    }
                    if(!ok) break;
                }

                if(board[s.x][s.y] == 'J' && !next.fire.count( mp(s.x, s.y) ))
                    board[s.x][s.y] = '.';

                if(ok) {
                    Q.push(next);
                    visited[next.x][next.y] = true;
                }
            } else if(nr < 0 || nr >= s.r || nc <= -1 || nc >= s.c) {
                return s.steps + 1;
            }
            tmp = sr;
            sr = -sc, sc = tmp;
        }
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d\n", &start.r, &start.c);
        start.fire.clear();

        REP(i, 0, start.r) {
            gets(board[i]);
            REP(j, 0, start.c) {
                if(board[i][j] == 'J') {
                    start.x = i, start.y = j;
                }
                if(board[i][j] == 'F') {
                    start.fire.insert( mp(i, j) );
                }
            }
        }
        int ans = bfs();
        if(ans < 0) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
}

