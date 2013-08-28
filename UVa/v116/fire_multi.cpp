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

#ifdef L
#include "../../debug.h"
#endif

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 1000 + 10;

typedef pair<int,int> ii;
#define mp make_pair

int R, C;
bool visited[MAXN][MAXN];
char board[MAXN][MAXN];
int parent[MAXN*MAXN][2];
vector<ii> points;

bool valid(int nr, int nc, int r, int c) {
    return (nr >= 0 && nr < r && nc >= 0 && nc < c && !visited[nr][nc]);
}

bool bfs_fire() {
    queue< pair<ii, int> > Q;
    memset(visited, false, sizeof(visited));

    REP(i, 0, points.size()) {
        Q.push( mp(points[i], 0) );
        visited[points[i].first][points[i].second] = true;
    }

    while(!Q.empty()) {
        ii current = Q.front().first;
        int cost = Q.front().second;
        Q.pop();

        if(board[current.first][current.second] == 'J')
            if(cost == parent[current.first * C + current.second][1])
                return false;

        int sr = 0, sc = 1;
        REP(i, 0, 4) {
            int nr = current.first + sr;
            int nc = current.second + sc;

            if(valid(nr, nc, R, C) && board[nr][nc] != '#') {
                Q.push( mp(ii(nr, nc), cost+1) );
                visited[nr][nc] = true;
            }
            int tmp = sr;
            sr = -sc, sc = sr;
        }
    }
    return true;
}

int bfs_player(ii start, int& end) {
    queue< pair<ii, int> > Q;
    memset(visited, false, sizeof(visited));

    Q.push( mp(start, 0) );
    visited[start.first][start.second] = true;

    while(!Q.empty()) {
        ii current = Q.front().first;
        int cost = Q.front().second;
        Q.pop();

        int sr = 0, sc = 1;

        REP(k, 0, 4) {
            int nr = current.first + sr;
            int nc = current.second + sc;

            if(valid(nr, nc, R, C) && board[nr][nc] == '.') {
                Q.push( mp(ii(nr, nc), cost+1) );
                visited[nr][nc] = true;

                parent[nr * C + nc][0] = current.first * C + current.second;
                parent[nr * C + nc][1] = cost + 1;

            } else if(nr < 0 || nr >= R || nc <= -1 || nc >= C) {
                end = current.first * C + current.second;
                return cost + 1;
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
        points.clear();

        ii player;

        REP(i, 0, R) {
            gets(board[i]);
            REP(j, 0, C) {
                if(board[i][j] == 'J') {
                    player = mp(i, j);
                }
                if(board[i][j] == 'F') {
                    points.push_back( mp(i, j) );
                }
            }
        }

        memset(parent, -1, sizeof(parent));
        int end = 0;

        int player_out = bfs_player(player, end);
        bool ok = true;

        while(end != -1) {
            int prev = end;
            int nr = prev / C, nc = prev % C;
            if(board[nr][nc] == '.')
                board[prev / C][prev % C] = 'J';
            end = parent[prev][0];
        }

        if(!bfs_fire()) puts("IMPOSSIBLE");
        else printf("%d\n", player_out);
    }
}

