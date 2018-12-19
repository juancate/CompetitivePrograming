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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
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

int T, N, K;
char S[MAXN], tmp[MAXN];

void assign(int left, int mid, int right) {
    if(S[mid] != '?') return;
    for(char c = '0'; c <= '2'; c++) {
        if(S[left] == c || c == S[right]) continue;
        S[mid] = c;
        break;
    }
}

string solve() {
    if(N == 1) {
        if(S[0] == '?') return "0";
        return S;
    }

    if(K == 1) {
        if(N > 1) return "NO";
        if(S[0] == '?') return "0";
        return S;
    }

    if(K == 2) {
        if(N & 1) return "NO";

        strcpy(tmp, S);
        bool pos = true;

        REP(i, 0, N) {
            if(S[i] == '?')
                S[i] = '0' + i%2;
            else if(S[i] != ('0' + i%2)) {
                pos = false;
                break;
            }
        }

        if(pos) return S;

        pos = true;
        strcpy(S, tmp);

        REP(i, 0, N) {
            if(S[i] == '?')
                S[i] = '0' + 1 - i%2;
            else if(S[i] != ('0' + 1 - i%2)) {
                pos = false;
                break;
            }
        }

        if(pos) return S;

        return "NO";
    }

    REP(i, 1, N) if(S[i] == S[i-1] && S[i] != '?') return "NO";

    if(S[0] == S[N-1] && S[0] != '?') return "NO";

    assign(N-1, 0, 1);

    REP(i, 1, N-1) {
        assign(i-1, i, i+1);
    }

    assign(N-2, N-1, 0);

    return S;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%s", &K, S);
        N = strlen(S);
        puts(solve().c_str());
    }
}

