#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

const int MAXN = 100000 + 10;

int games[MAXN];
int T, N, diff;

bool check(int mid) {
  int val = -INF;
  REP(i, N) {
    if(i <= mid) continue;
    val = max(val, games[i] - games[mid]);
  }
  if(val <= diff) return true;
  if(val > diff) diff = val;
  D(val); D(diff);
  return false;
}

int binarySearch() {
  int lo = 0, hi = N;
  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;
    D(mid);
    if(check(mid)) hi = mid; // +
    else lo = mid + 1; // -
  }
  return diff;
}

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    diff = 0;
    scanf("%d", &games[0]);
    for(int i = 1; i < N; i++) {
      scanf("%d", &games[i]);
    }
    binarySearch();
    if(diff == 0) puts("UNFIT");
    else printf("%d\n", diff);
  }
}

