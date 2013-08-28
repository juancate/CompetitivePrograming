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

map<int64, int64> memo;

int64 solve(int64 n) {
    if(n == 0) return 0;
    if(memo.count( n )) return memo[n];

    return memo[n] = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
}

int main() {
    int64 N, ans;
    while(~scanf("%lld", &N)) {
        ans = solve(N / 2LL) + solve(N / 3LL) + solve(N / 4LL);
        ans = max(N, ans);
        printf("%lld\n", ans);
    }
}

