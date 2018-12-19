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

struct move {
    char c; int v;

    move(char m = ' ', int u = 0) {
        c = m; v = u;
    }

    string print() {
        stringstream s;
        if(c == 's') {
            s << "- Switch on light in room ";
        }
        else if(c == 'm'){
            s << "- Move to room ";
        }
        else {
            s << "- Switch off light in room ";
        }
        s << (v+1) << '.';
        return s.str();
    }
};

struct State
{
    int room;
    int mask;

    vector<move> moves;

    State(int r = 0, int ma = 0, vector<move> m = vector<move>())
    {
        room = r; mask = ma;
        moves = m;
    }
};

int r, d, s, villa;
vector< vector<int> > G, lights;
bool visited[11][1<<11];

void bfs(int start, int mask) {
    memset(visited, false, sizeof(visited));
    queue< State > Q;
    Q.push( State(0, 1) );

    while(!Q.empty()) {
        State current = Q.front();
        Q.pop();

        if(current.room == r-1 && current.mask == (1 << (r-1))) {
            cout << "Villa #" << villa++ << endl;
            cout << "The problem can be solved in " << current.moves.size() << " steps:\n";
            FOREACH(s, current.moves) {
                cout << s->print() << endl;
            }
            cout << endl;
            return; // end
        }

        if(visited[current.room][current.mask])
            continue;

        visited[current.room][current.mask] = true;

        for(int i = 0; i < (int)lights[current.room].size(); i++) {
            int next = lights[current.room][i];

            if(next == current.room) continue;

            if(current.mask & (1 << next)) { // is on, then turn off
                int next_mask = (current.mask & ~(1 << next));
                vector<move> next_move = current.moves;
                next_move.push_back( move('o', next) );
                Q.push( State(current.room, next_mask, next_move) );
            }
            else { // is off, the turn on
                int next_mask = (current.mask | (1 << next));
                vector<move> next_move = current.moves;
                next_move.push_back( move('s', next) );
                Q.push( State(current.room, next_mask, next_move) );
            }
        }

        for(int i = 0; i < (int)G[current.room].size(); i++) {
            int next = G[current.room][i];

            if(current.mask & (1 << next)) { // is on, then move
                int next_mask = current.mask;
                vector<move> next_move = current.moves;
                next_move.push_back( move('m', next) );
                Q.push( State(next, next_mask, next_move) );
            }
        }
    }

    cout << "Villa #" << villa++ << endl;
    cout << "The problem cannot be solved.\n" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    villa = 1;
    while(cin >> r >> d >> s) {
        if((r|d|s) == 0) break;

        G.assign(r, vector<int>());
        lights.assign(r, vector<int>());

        REP(i, 0, d) {
            int a, b; cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        REP(i, 0, s) {
            int a, b; cin >> a >> b;
            a--, b--;
            lights[a].push_back(b);
        }
        bfs(0, 1);
    }
}

