#include <algorithm>
#include <complex>
#include <list>
#include <stack>
#include <bitset>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <map>
#include <cctype>
#include <string>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

#define D(x) cerr << #x " = " << (x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int MAXN = 15 + 5;

char board[MAXN][MAXN];
char cmd[MAXN + MAXN + MAXN];
int R, C;

bool valid(int r, int c) {
  return (r >= 0 and r < R and c >= 0 and c < C and board[r][c] != '#');
}

int main() {
  int cases = 1;
  while(~scanf("%d %d\n", &R, &C) and (R|C) != 0) {
    REP(i, 0, R)
      fgets(board[i], sizeof(board[i]), stdin);
    fgets(cmd, sizeof(cmd), stdin);

    int wr, wc;
    bool found = false;
    REP(i, 0, R) {
      REP(j, 0, C) {
        if(board[i][j] == 'w' or board[i][j] == 'W') {
          wr = i, wc = j;
          found = true;
          break;
        }
      }
      if(found) break;
    }

    int n = strlen(cmd);
    int complet = true;
    REP(i, 0, R) {
      REP(j, 0, C) if(board[i][j] == 'b') {
        complet = false;
        break;
      }
      if(!complet) break;
    }

    REP(i, 0, n) {
      if(complet) break;
      int r = 0, c = 0;
      complet = true;
      switch(cmd[i]) {
        case 'U':
          r = -1, c = 0; break;
        case 'D':
          r = 1, c = 0; break;
        case 'L':
          r = 0, c = -1; break;
        case 'R':
          r = 0, c = 1; break;
      }

      int nr = wr + r, nc = wc + c;

      if(valid(nr, nc)) {
        if(board[nr][nc] == '.') {
          if(board[wr][wc] == 'W') board[wr][wc] = '+';
          else board[wr][wc] = '.';
          board[nr][nc] = 'w';
          wr = nr, wc = nc;
        } else if(board[nr][nc] == '+') {
          if(board[wr][wc] == 'W') board[wr][wc] = '+';
          else board[wr][wc] = '.';
          board[nr][nc] = 'W';
          wr = nr, wc = nc;
        } else if(board[nr][nc] == 'b') {
          int nnr = nr + r, nnc = nc + c;
          if(valid(nnr, nnc) and board[nnr][nnc] != 'b' and board[nnr][nnc] != 'B') {
            if(board[nnr][nnc] == '.') {
              if(board[wr][wc] == 'W') board[wr][wc] = '+';
              else board[wr][wc] = '.';
              board[nr][nc] = 'w';
              board[nnr][nnc] = 'b';
              wr = nr, wc = nc;
            } else if(board[nnr][nnc] == '+') {
              if(board[wr][wc] == 'W') board[wr][wc] = '+';
              else board[wr][wc] = '.';
              board[nr][nc] = 'w';
              board[nnr][nnc] = 'B';
              wr = nr, wc = nc;
            }
          }
        } else if(board[nr][nc] == 'B') {
          int nnr = nr + r, nnc = nc + c;
          if(valid(nnr, nnc) and board[nnr][nnc] != 'b' and board[nnr][nnc] != 'B') {
            if(board[nnr][nnc] == '.') {
              if(board[wr][wc] == 'W') board[wr][wc] = '+';
              else board[wr][wc] = '.';
              board[nr][nc] = 'W';
              board[nnr][nnc] = 'b';
              wr = nr, wc = nc;
            } else if(board[nnr][nnc] == '+') {
              if(board[wr][wc] == 'W') board[wr][wc] = '+';
              else board[wr][wc] = '.';
              board[nr][nc] = 'W';
              board[nnr][nnc] = 'B';
              wr = nr, wc = nc;
            }
          }
        }
      }
      REP(i, 0, R) {
        REP(j, 0, C) if(board[i][j] == 'b') {
          complet = false;
          break;
        }
        if(!complet) break;
      }
      if(complet) break;
    }

    printf("Game %d: ", cases++);
    puts(((complet)? "complete" : "incomplete"));
    REP(i, 0, R) printf("%s", board[i]);
  }
}
