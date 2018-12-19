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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

typedef vector<string> vs;
typedef pair<int, int> ii;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int n, m;

bool valid(int r, int c) {
    return (r >= 0 && r < 3*n && c >= 0 && c < 3*m);
}

bool bfs(const vs& maze, const ii& start) {
    bool visited[maze.size()][maze[0].size()];
    memset(visited, false, sizeof(visited));

    queue< ii > Q;
    Q.push(start);
    visited[start.first][start.second] = true;
    bool first = true;

    while(!Q.empty()) {
        ii state = Q.front();
        Q.pop();

        if (!first) {
            if (maze[state.first][state.second] == 'S') return true;
        } else {
            first = false;
        }


        REP(i, 0, 4) {
            int nr = state.first + dr[i];
            int nc = state.second + dc[i];

            if (nr < 0) nr = (nr + 3*n) % (3*n);
            else if (nr >= 3*n) nr = nr % (3*n);

            if (nc < 0) nc = (nc + 3*m) % (3*m);
            else if (nc >= 3*m) nc = nc % (3*m);

            if (valid(nr, nc) && maze[nr][nc] != '#' && !visited[nr][nc]) {
                ii next = make_pair(nr, nc);
                Q.push(next);
                visited[nr][nc] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    vs maze(n + n + n);
    ii start;

    cin.get();
    REP(i, 0, n) {
        REP(j, 0, m) {
            char ch = cin.get();
            if(ch == 'S') {
                start = make_pair(i+n, j+m);
            }
            maze[i].push_back(ch);
        }
        maze[i] = maze[i + n] = maze[i + n + n] = maze[i] + maze[i] + maze[i];
        cin.get();
    }


    if(bfs(maze, start)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

