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

struct State {
    int row, col, places;
    string route;

    State(int r = 0, int c = 0, int p = 0) {
        row = r; col = c;
        places = p;
        route = "";
    }
};

const int maxn = 22;
const int maxp = 11;

const int dr[] = {0, -1, 1, 0}; // East, North, South, West
const int dc[] = {1, 0, 0, -1};

int n, m, cnt_places;
vector<string> board;
int mapping[maxn][maxn];
bool visited[maxn][maxn][1<<maxp];

bool valid(int nr, int nc) {
    return (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            board[nr][nc] != '#' && board[nr][nc] != 'X');
}

void bfs(int start_row, int start_col) {
    memset(visited, false, sizeof(visited));

    queue<State> Q;
    Q.push( State(start_row, start_col, 0) );
    int places = 0;
    string ans;

    while(!Q.empty()) {
        State current = Q.front();
        Q.pop();

        if(board[current.row][current.col] == 'S') {
            int current_places = __builtin_popcount(current.places);

            if(current_places > places) {
                places = current_places;
                ans = current.route;
            }
            else if(current_places == places) {
                if(current.route.size() < ans.size() ||
                   (current.route.size() == ans.size() && current.route < ans))
                    ans = current.route;
            }
        }

        if(visited[current.row][current.col][current.places])
            continue;

        visited[current.row][current.col][current.places] = true;

        for(int k = 0; k < 4; k++) {
            int nr = current.row + dr[k];
            int nc = current.col + dc[k];

            if(valid(nr, nc)) {
                int p = current.places;
                if(board[nr][nc] == '*')
                    p |= (1 << mapping[nr][nc]);

                State next(nr, nc, p);
                next.route = current.route;

                switch(k) {
                    case 0:
                        next.route.push_back('E');
                        break;
                    case 1:
                        next.route.push_back('N');
                        break;
                    case 2:
                        next.route.push_back('S');
                        break;
                    case 3:
                        next.route.push_back('W');
                }

                Q.push(next);
            }
        }
    }

    if(places == 0)
        cout << "Stay home!" << endl;
    else
        cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "a", stderr);
#else
    ios_base::sync_with_stdio(false);
#endif

    while(cin >> n >> m) {
        if((n|m) == 0) break;

        cin.get();
        board.assign(n, "");

        int start_row = -1, start_col = -1;
        cnt_places = 0;
        memset(mapping, -1, sizeof(mapping));

        REP(i, 0, n) {
            getline(cin, board[i]);

            REP(j, 0, m) {
                if(board[i][j] == 'S') {
                    start_row = i; start_col = j;
                }
                if(board[i][j] == '*') {
                    mapping[i][j] = cnt_places++;
                }
            }
        }
        if(start_row != -1 && start_col != -1)
            bfs(start_row, start_col);
        else
            cout << "Stay home!" << endl;
    }
}

