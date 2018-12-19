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

const int MAXN = 100 + 10;

int N;
int coins[MAXN];
int dp[30001];

void solve(int price) {
    REP(i, 0, 30001) dp[i] = INF;

    dp[0] = 0;

    REP(i, 0, N) {
        for(int v = 30000; v >= 0; v--) {
            if(dp[v] < INF && v + coins[i] < 30001) {
                dp[v + coins[i]] = min(dp[v + coins[i]], dp[v] + 1);
            }
        }
    }

    int index = price;
    while(index < 30001 && dp[index] == INF) index++;

    printf("%d %d\n", index, dp[index]);
}


int main() {
    int T, price;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &price, &N);
        REP(i, 0, N) scanf("%d", coins + i);
        solve(price);
    }
}

