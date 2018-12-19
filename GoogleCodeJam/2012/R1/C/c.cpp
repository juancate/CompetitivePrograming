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
const long long INFLL = (int)(1e18);
const double EPS = 1e-13;

const int MAXN = 100 + 10;

int T, N, M;
pair<int64, int> boxes[MAXN], toys[MAXN];
int64 dp[MAXN][MAXN];

// to solve large need to add dp-cache

int64 solve(int i, int j, int64 cb, int64 ct) {
    if(i >= N) return 0;
    if(j >= M) return 0;

    //if(dp[i][j] != -1) return dp[i][j];

    if (boxes[i].second != toys[j].second) 
        return max(solve(i, j+1, cb, toys[j+1].first),
                   max(solve(i+1, j, boxes[i+1].first, ct),
                       solve(i+1, j+1, boxes[i+1].first, toys[j+1].first)));

    int64 ans = 0;

    if(cb > ct) {
        ans = ct + solve(i, j+1, cb - ct, toys[j+1].first);
    } else if(cb < ct) {
        ans = cb + solve(i+1, j, boxes[i+1].first, ct - cb);
    } else {
        ans = ct + solve(i+1, j+1, boxes[i+1].first, toys[j+1].first);
    }
    
    return ans;
}


int main() {
    scanf("%d", &T);
    REP(id, 1, T+1) {
        scanf("%d %d", &N, &M);
        memset(dp, -1, sizeof(dp));
        REP(i, 0, N) boxes[i] = make_pair(0,0);
        REP(i, 0, M) toys[i] = make_pair(0,0);
        REP(i, 0, N) scanf("%lld %d", &boxes[i].first, &boxes[i].second);
        REP(i, 0, M) scanf("%lld %d", &toys[i].first, &toys[i].second);
        int64 ans = solve(0, 0, boxes[0].first, toys[0].first);
        
        printf("Case #%d: %lld\n", id, ans);
    }
}

