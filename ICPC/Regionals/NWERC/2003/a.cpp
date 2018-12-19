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

typedef pair < int , int > PI;

int solvenlogk(const vector<int>& A) {
    int N = A.size(), j=-1, t;
    vector<int> pre(N,-1), res;
    map<int,int> m;
    map<int,int>::iterator k, l;
    REP(i, 0, N) {
        if(m.insert(PI(A[i], i)).second) {
            k = m.find(A[i]);
            l = k;
            k++;
            if(l == m.begin())
                pre[i]=-1;
            else {
                l--;
                pre[i]=l->second;
            }
            if(k != m.end())
                m.erase(k);
        }
    }
    k = m.end();
    k--;
    j = k->second;
    while (j != -1) {
        res.push_back(A[j]);
        j = pre[j];
    }
    //reverse(ALL(res));
    return res.size();
}


int main() {
    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        vector<int> seq(N);
        REP(i, 0, N) scanf("%d", &seq[i]);
        printf("%d\n", solvenlogk(seq));
    }
}

