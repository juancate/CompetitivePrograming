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


int main() {
    int T, N, i, j;
    scanf("%d", &T);

    REP(id, 1, T+1) {
        scanf("%d", &N);
        vector<int> numbers(N), sums((1<<N));
        REP(k, 0, N) scanf("%d", &numbers[k]);

        int finded = false;
        unsigned subset;
        for(subset = 1; subset <= (1<<N); subset++) {
            int sumA = 0;
            for(i = 0; i < N; i++) {
                if(subset & (1 << i)) 
                    sumA += numbers[i];
            }
            sums[subset] = sumA;
        }

        printf ("Case #%d:\n",id);
                
        for (i = 0; i < sums.size(); i++) {
            for (j = i+1; j < sums.size(); j++) {
                if (sums[i] == sums[j] and (i & j) == 0) {
                    finded = true;
                    break;
                }
            }
            if(finded) break;
        }

        if(!finded) {
            puts("Impossible");
            continue;
        }

        bool first = true;
        for(int k = 0; k < N; k++) {
            if(i & (1 << k)) {
                if(!first) printf(" ");
                else first = false;
                printf ("%d", numbers[k]);
            }
        }
        puts("");
        first = true;
        for(int k = 0; k < N; k++) {
            if(j & (1 << k)) {
                if(!first) printf(" ");
                else first = false;
                printf ("%d", numbers[k]);
            }
        }
        
        puts("");
    }
}

