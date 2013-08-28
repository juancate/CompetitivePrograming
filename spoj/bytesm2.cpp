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

template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
  return ( os << "(" << z.first << ", " << z.second << ",)" );
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const vector<T>& z){
  os << "[ ";
  REP(i,0,z.size())os << z[i] << ", " ;
  return ( os << "]" << endl);
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const set<T>& z){
  os << "set( ";
  FOREACH(p,z)os << (*p) << ", " ;
  return ( os << ")" << endl);
}
template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
  os << "{ ";
  FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
  return ( os << "}" << endl);
}

const int INF = 1000000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

const int MAXH = 100 + 10;
const int MAXW = 100 + 10;

int T, H, W, ans;
int board[MAXH][MAXW], dp[MAXH][MAXW];

bool valid(int col) {
    return (col >= 0 and col < W);
}

int solve(int row, int col) {
    if(dp[row][col] != -1) return dp[row][col];

    int a, b, c;
    a = b = c = 0;

    if(row - 1 >= 0) {
        if(valid(col - 1)) 
            a = solve(row - 1, col - 1);
        if(valid(col + 1))
            c = solve(row - 1, col + 1);
        b = solve(row - 1, col);
    }

    dp[row][col] = board[row][col] + max(a, max(b, c));

    return dp[row][col];
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &H, &W);
        REP(i, 0, H) REP(j, 0, W) scanf("%d", &board[i][j]);
        
        REP(i, 0, H) REP(j, 0, W) dp[i][j] = -1;

        ans = -1;
        // top down + memoization
        //REP(i, 0, W) ans = max(ans, solve(H-1, i));
        
        // buttom up
        REP(i, 0, W) dp[0][i] = board[0][i];

        REP(i, 1, H) {
            REP(j, 0, W) {
                if(j - 1 >= 0) 
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                if(j + 1 < W) 
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1]);

                dp[i][j] = max(dp[i][j], dp[i-1][j]) + board[i][j];
                
                if(i == H - 1) ans = max(ans, dp[i][j]);
            }
        }
        
        printf("%d\n", ans);
    }

}

