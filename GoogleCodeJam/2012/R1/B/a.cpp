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

const int MAXN = 200 + 10;

int T, N, sum;
int scores[MAXN];
double porcentage[MAXN];

bool check(double y, int i) {
    double total_score = scores[i] + (sum * y);
    double s = 0.0;
    REP(j, 0, N) if(j != i and scores[j] < total_score) {
        s += (total_score - scores[j]) / sum;
    }
    return (y + s) > 1.0;
}

double binSearch(int i) {
    double lo = 0.0, hi = 1.0;
    while((hi - lo) > EPS) {
        double mid = (hi + lo) / 2.;
        if(check(mid, i)) 
            hi = mid;
        else lo = mid;
    }
    return lo;
}

int main() {
    scanf("%d", &T);
    REP(id, 1, T+1) {
        scanf("%d", &N);
        sum = 0;
        REP(i, 0, N) {
            scanf("%d", scores + i);
            sum += scores[i];
            porcentage[i] = 0.0;
        }

        printf("Case #%d:", id);

        REP(i, 0, N) {
            double ans = binSearch(i) * 100.;            
            printf(" %lf", ans);
        }
        puts("");
    }
}

