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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 60 + 10;

int n, q, cases, w[MAXN], m[MAXN];
int64 binomial[61][61], bpi[MAXN], dp[MAXN][MAXN];

void prepocessing() {
    REP(i, 0, 61) {
        REP(j, 0, i+1) {
            if(j == 0 || j == i) binomial[i][j] = 1;
            else binomial[i][j] = binomial[i-1][j-1] + binomial[i-1][j];
        }
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        REP(j, 0, n) REP(k, 0, q) dp[j][k] = 0;

        m[i]--;

        for(int row = 0; row < n; row++)
            dp[row][0] = 1;

        for(int j = 1; j <= m[0] && j * w[0] <= q - 1; j++)
            dp[0][j * w[0]] = binomial[m[0]][j];

        for(int col = 1; col < q; col++) {
            for(int row = 1; row < n; row++) {
                dp[row][col] = dp[row - 1][col];
                for(int j = 1; j <= m[row] && col - j * w[row] >= 0; j++) {
                    dp[row][col] += binomial[m[row]][j] * dp[row - 1][col - j * w[row]];
                }
            }
        }

        bpi[i] = 0;
        for(int j = max(q - w[i], 0); j < q; j++)
            bpi[i] += dp[n-1][j];

        m[i]++;
    }
}

int main() {
    prepocessing();
    cases = 1;

    while(~scanf("%d%d", &n, &q) && (n|q) != 0) {
        REP(i, 0, n) {
            scanf("%d%d", w+i, m+i);
        }

        solve();

        printf("Case %d: ", cases++);
        REP(i, 0, n) {
            if(i) printf(" ");
            printf("%lld", bpi[i]);
        }
        puts("");
    }
}

