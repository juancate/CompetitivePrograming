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
#define REP(i,a,n) for(int i=(a); i<n; i++)
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

const int MAXN = 10000 + 10;

int M, N, T;
int beers[MAXN], burgers[MAXN];

void calcbeer(int t) {
  beers[0] = 0;
  REP(i, 1, t+1) {
    int a = (N > i)? i : beers[i - N];
    int b = (M > i)? i : beers[i - M];
    beers[i] = min(a, b);
  }
}

void calcburger(int t) {
  burgers[0] = 0;
  REP(i, 1, t+1) {
    int ab = (N > i)? INF : beers[i - N];
    int bb = (M > i)? INF : beers[i - M];
    if(ab == bb and N <= i and M <= i) {
      burgers[i] = max(burgers[i - N], burgers[i - M]) + 1;
    } else if(ab < bb and N <= i) {
      burgers[i] = burgers[i - N] + 1;
    } else if(M <= i) {
      burgers[i] = burgers[i - M] + 1;
    } else {
      burgers[i] = 0;
    }
  }
}

int main() {
  while(scanf("%d %d %d", &M, &N, &T) == 3) {
    memset(beers, 0, sizeof(beers));
    memset(burgers, -1, sizeof(burgers));
    calcbeer(T);
    calcburger(T);
    printf("%d", burgers[T]);
    if(beers[T] != 0) printf(" %d", beers[T]);
    puts("");
  }
}

