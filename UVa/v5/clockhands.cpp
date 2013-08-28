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

namespace IO {
#define MAXBUFF (1<<18)
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;
  
  inline char read_char() {
    if( p == buffer+MAXBUFF ) {
      fread( buffer, 1, MAXBUFF, stdin );
      p = buffer;
    }
    return *p++;
  }
  
  inline int read_signed_int() {
    char c;
    while( !isdigit(c = read_char()) and c != '-' );
    int sign = 1;
    if (c == '-') sign = -1, c = read_char();
    int ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret * sign;
  }
  
  inline int read_unsigned_int() {
    char c;
    while( !isdigit(c = read_char()) );
    int ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret;
  }
}

int main() {
  int h, m;
  //while(scanf("%d:%d", &h, &m) == 2 and (h|m) != 0 ) {
  while(true) {
    h = IO::read_unsigned_int();
    m = IO::read_unsigned_int();
    if((h|m) == 0) break;
    
    double ans = (h * 60 * .5) + (m * .5) - (m * 6);

    if(ans < 0) ans *= -1;
    if(ans > 180) ans = 360. - ans;

    printf("%.3lf\n", ans);
  }
}

