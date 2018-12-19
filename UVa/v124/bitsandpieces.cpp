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
  int T;
  scanf("%d", &T);
  while(T--) {
    unsigned int C, D, A, B;
    scanf("%d %d", &C, &D);

    bool ok = true;
    bool highest = false;
    A = B = 0;
    
    for(int i = 31; i >= 0; i--) {
      if(((C & (1 << i)) & (D & (1 << i))) != 0) {
        A |= (1 << i);
        B |= (1 << i);
      } else if((C & (1 << i)) != 0 and (D & (1 << i)) == 0) {
        ok = false;
        break;
      }
      else if((C & (1 << i)) == 0 and (D & (1 << i)) != 0) {
        if(!highest) B |= (1 << i), highest = true;
        else A |= (1 << i);
      }
    }

    if(!ok) puts("-1");
    else {
      printf("%d %d\n", A, B);
    }
  }
}

