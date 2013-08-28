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

const int MAXN = 100 + 10;

int surprises[MAXN], normals[MAXN];

bool surprise(int i, int j, int k) {
  if(abs(i - j) < 2 and abs(i - k) < 2 and abs(j - k) < 2) return false;
  if(abs(i - j) <= 2 and abs(i - k) <= 2 and abs(j - k) <= 2) return true;
  return false;
}

bool valid(int i, int j, int k) {
  if(abs(i-j) < 2 and abs(i-k) < 2 and abs(j-k) < 2) return true;
  if(abs(i - j) <= 2 and abs(i - k) <= 2 and abs(j - k) <= 2) return true;
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(cases, 1, T+1) {
    int N, S, P;
    scanf("%d %d %d", &N, &S, &P);

    memset(surprises, 0, sizeof(surprises));
    memset(normals, 0, sizeof(normals));

    REP(n, 0, N) {
      int ti;
      scanf("%d", &ti);

      if(ti < P) continue;

      for(int i = 10; i >= 0; i--) {
        for(int j = i; j >= i-2 and j >= 0; j--) {
          for(int k = j; k >= j-2 and k >= i-2 and k >= 0; k--) {

            if(valid(i, j, k) and (i + j + k) == ti) {
              int max = std::max(i, std::max(j, k));

              if(max >= P) {
                if(surprise(i, j, k)) {
                  surprises[n]++;
                } else {
                  normals[n]++;
                }
              }
            }
          }
        }
      }
    }

    int ans = 0;

    REP(i, 0, N) {
      if(normals[i] > 0) {
        ans++;        
      }
      else if(surprises[i] > 0 and S > 0) {
        ans++;
        S--;
      }
    }
    
    printf("Case #%d: %d\n", cases, ans);
  }
}

