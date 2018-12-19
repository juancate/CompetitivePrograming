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

char name[1000 + 10];

int main() {
    int N, Q;
    while(~scanf("%d", &N)){
        vector< pair<string, int> > v(N);
        vector< pair<string, int> >::iterator b;

        REP(i, 0, N) {
            int x;
            scanf("%s %d", name, &x);
            v[i] = make_pair( name, x );
        }

        sort( ALL(v) );
        
        scanf("%d", &Q);

        while(Q--) {
            scanf("%s", name);

            string ans = "";
            int max_priority = -INF;
            pair< string, int > p = make_pair( name, max_priority );

            b = lower_bound( ALL(v), p );
            int length = p.first.length();

            if(p.first != b->first.substr(0, length)) {
                puts("NO");
            } else {
                while(b != v.end() and p.first == b->first.substr(0, length)) {
                    if(b->second > max_priority) {
                        max_priority = b->second;
                        ans = b->first;
                    }
                    b++;
                }
                puts(ans.c_str());
            }
        }
    }
}

