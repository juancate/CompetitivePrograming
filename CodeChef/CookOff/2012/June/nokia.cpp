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

const int MAXN = 30 + 10;
bool visited[MAXN];
int T, N, K, min_wire;

int solve(int x, int k) {
    int left = 0, right = 0;

    for (int i = x-1; i >= 0; i--) {
        if (visited[i]) {
            left = x - i;
            break;
        }
    }

    for (int i = x+1; i <= N+1; i++) {
        if (visited[i]) {
            right = i + 1 - x;
            break;
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;

            int ret = -INF;
            if(k >= left + right)
                ret = solve(i, k - left - right);

            //if (ret < min_wire) continue;
            ans = max(ans, ret);

            visited[i] = false;
        }
    }
    min_wire = max(min_wire, ans + left + right);
    return min_wire;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &K);
        int ans = -1;
        memset(visited, false, sizeof(visited));
        min_wire = -INF;
        visited[0] = visited[N+1] = true;
        REP(i, 1, N+1) {
            int t = solve(i, K);
            visited[i] = true;
            //memset(visited, false, sizeof(visited));
            ans = max(ans, K - t);
            visited[i] = false;
            D(t);
        }
        if(ans < 0) printf("-1\n");
        else printf("%d\n", ans);
    }
}

