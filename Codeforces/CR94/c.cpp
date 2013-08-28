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

typedef pair< pair< int, vector<string> >, pair<int, int> > state;

#define row second.first
#define col second.second
#define turn first.first
#define board first.second
#define state(t,b,r,c) make_pair(make_pair(t,b), make_pair(r,c))

int dr[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, -1, -1, 1};

bool valid_move(int r, int c) {
  return r >= 0 && r < 8 && c >= 0 && c < 8;
}

void get_pos(vector<string> b, int& r, int& c) {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(b[i][j] == 'M') {
        r = i; c = j;
        return;
      }
    }
  }
}

bool bfs(vector<string> b) {
  queue<state> q;
  set<state> used;
  int r, c;

  get_pos(b, r, c);

  state curr = state(0,b,r,c);
  q.push(curr);
  used.insert(curr);

  while(!q.empty()) {
    curr = q.front();
    q.pop();

    r = curr.row;
    c = curr.col;

    if(curr.board[r][c] == 'A')
      return true;

    if(curr.turn == 0) {
      // move maria

      for(int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(valid_move(nr, nc)) {
          if(curr.board[nr][nc] != 'S') {
            vector<string> nb = curr.board;
            if(curr.board[nr][nc] == 'A') return true;
            nb[r][c] = '.'; nb[nr][nc] = 'M';
            state next = state(curr.turn^1, nb, nr, nc);
            if(!used.count(next)) {
              q.push(next);
              used.insert(next);
            }
          }
        }
      }
      state next = state(curr.turn^1, curr.board, r, c);
      if(!used.count(next)) {
        q.push(next);
        used.insert(next);
      }
    }
    else {
      // move statues
      bool valid = true;
      vector<string> nb = curr.board;
      for(int i = 7; i >= 0; i--) {
        for(int j = 0; j < 8; j++) {
          if(nb[i][j] == 'S') {
            int nr = i + 1;
            nb[i][j] = '.';
            if(nr < 8) {
              if(nb[nr][j] == 'M') valid = false;
              nb[nr][j] = 'S';
            }
          }
        }
      }
      if(!valid) continue;
      state next = state(curr.turn^1, nb, r, c);
      if(!used.count(next)) {
        q.push(next);
        used.insert(next);
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);

  vector<string> b(8);
  for(int i = 0; i < 8; i++)
    cin >> b[i];

  cout << (bfs(b)? "WIN" : "LOSE") << endl;

  return 0;
}

