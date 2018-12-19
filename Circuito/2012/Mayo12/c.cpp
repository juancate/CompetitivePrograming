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

const int MAXB = 500 + 10;
const int MAXC = 2500 + 10;

int results[MAXB][MAXC];
int b, c, cases;

int compare(int x, int y) {
    int v1, v2;
    v1 = v2 = 0;

    REP(i, 0, b) {
        if(results[i][x] < results[i][y]) v1++;
        else v2++;
    }

    if(v1 > v2) return x;
    return y;
}

int main() {
    cases = 1;
    while(~scanf("%d%d", &b, &c) && (b|c) != 0) {
        REP(i, 0, b) {
            REP(j, 0, c) {
                int k;
                scanf("%d", &k);
                results[i][k] = j;
            }
        }

        int winner = 0;

        REP(y, 1, c) {
            winner = compare(winner, y);
        }

        bool ok = true;
        REP(y, 0, winner) {
            if(compare(winner, y) != winner) {
                ok = false;
                break;
            }
        }

        printf("Case %d: ", cases++);
        if(ok)
            printf("%d\n", winner);
        else puts("No Condorcet winner");
    }
}

