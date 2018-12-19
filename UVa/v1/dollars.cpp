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

const int N = 11;
int coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

const int MAXK = 30000 + 5;
int64 dp[MAXK];
/*
top-down with memo
int64 dp[N][MAXK];

int64 solve(int coin, int money) {
    if(money == 0) return 1;
    if(money < 0 || coin >= N) return 0;
    if(dp[coin][money] != -1) return dp[coin][money];
    return dp[coin][money] = solve(coin, money - coins[coin]) + solve(coin + 1, money);
}
*/
int main() {
    int money, c;
    dp[0] = 1;
    REP(i, 0, N) {
        REP(s, coins[i], MAXK) {
            dp[s] += dp[s - coins[i]];
        }
    }

    while(~scanf("%d.%d", &money, &c) && (money+c)) {
        //int64 ways = solve(0, int((money + 1e-5) * 100));
        int value = money * 100 + c;
        printf("%3d.%.2d%17lld\n", money, c, dp[value]);
    }
}

