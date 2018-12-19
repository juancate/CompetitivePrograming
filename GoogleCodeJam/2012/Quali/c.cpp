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

const int MAXN = 2000000 + 10;
const int N = 10;

vector<bool> checked(MAXN, false);
int pot[N];

int main() {
  pot[0] = 1;
  REP(i, 1, N) pot[i] = 10 * pot[i - 1];

  int T;
  scanf("%d", &T);
  REP(cases, 1, T+1) {
    int A, B;
    scanf("%d %d", &A, &B);
    
    int n = 0, cnt = 0;
    for(int d = B; d > 0; d /= 10) n++;
    
    for(int i = A; i <= B; i++) {
      for(int j = 1; pot[j] <= B; j++) {
        int k = (i % pot[j]) * pot[n - j] + (i / pot[j]);

        if(k >= A and k <= B and k > i) {
          if(!checked[k]) cnt++;
          checked[k] = true;
        }
      }
      // Clear marked in case any other number recycles it
      for(int j = 1; pot[j] <= B; j++) {
        int k = (i % pot[j]) * pot[n - j] + (i / pot[j]);
        if(k < MAXN)
          checked[k] = false;
      }
    }

    printf("Case #%d: %d\n", cases, cnt);
  }
}

