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
#define REP(i,n) for(int i=0; i<n; i++)
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
  REP(i,z.size())os << z[i] << ", " ;
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

int calcbeer(int t) {
  int & r = beers[t];
  
  if(r != INF) return r;

  int a, b;
  if(N > t) a = t;
  else a = calcbeer(t - N);

  if(M > t) b = t;
  else b = calcbeer(t - M);

  r = min(r, min(a, b));
  return r;
}

int calcburger(int t) {
  int & r = burgers[t];

  if(r != -1) return r;

  int ab;
  if(N > t) ab = INF;
  else ab = beers[t - N]; // ! check t < N
  int bb; 
  if(M > t) bb = INF;
  else bb = beers[t - M];

  if(ab == bb and N <= t and M <= t) {
    r = max(calcburger(t - N), calcburger(t - M)) + 1;
  } else if(ab < bb and N <= t) {
    r = calcburger(t - N) + 1;
  } else if(M <= t) {
    r = calcburger(t - M) + 1;
  } else r = 0;

  return r;
}

int main() {
  while(scanf("%d %d %d", &M, &N, &T) == 3) {
    REP(i, T+1) beers[i] = INF, burgers[i] = -1;
    beers[0] = burgers[0] = 0;
    int beer = calcbeer(T);
    int burger = calcburger(T);

    printf("%d", burger);
    if(beer != 0) printf(" %d", beer);
    puts("");
  }
}

