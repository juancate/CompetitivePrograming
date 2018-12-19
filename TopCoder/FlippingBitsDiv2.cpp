#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define ALL_BITS 0xFFFFFFFF

typedef long long int64;
const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = (1e-19);

using namespace std;
// BEGIN CUT HERE
#define D(x) cerr << #x << " = " << x << endl;
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  REP(i,0,z.size())os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; FOREACH(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class FlippingBitsDiv2 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int getmin(vector <string> S, int M);
};

const int maxn = 55*55;

string B;
int n, front[maxn], zeroes[maxn], back[maxn], z2[maxn];

int FlippingBitsDiv2::getmin(vector <string> S, int M) {
  B.clear();
  memset(front, 0, sizeof(front));
  memset(back, 0, sizeof(back));
  memset(zeroes, 0, sizeof(zeroes));
  memset(z2, 0, sizeof(z2));

  for (int i = 0; i < S.size(); i++)
    B += S[i];
  n = B.size();

  for (int i = 0; i < n; i++) {
    front[i] = B[i] == '1';
    if (i) front[i] += front[i-1];

    zeroes[i] = B[i] == '0';
    if (i) zeroes[i] += zeroes[i-1];
  }

  for (int i = n-1; i >= 0; i--) {
    back[i] = (B[i] == '1') + back[i+1];
    z2[i] = (B[i] == '0') + z2[i+1];
  }

  int best = int(1e9);
  for (int i = 1; i * M <= n; i++) {
    for (int j = 1; j * M <= n; j++) {
      int x = i * M - 1;
      int y = n-j * M;

      if (y <= x) break;

      int curr = 2;
      curr += front[x] + back[y];
      curr += (zeroes[y-1] - zeroes[x]);
      best = min(best, curr);
    }
  }

  for (int i = 1; i * M <= n; i++) {
    int x = i * M - 1;
    int curr = 1 + front[x] + z2[x+1];
    best = min(best, curr);
  }
  for (int i = 1; i * M <= n; i++) {
    int x = n - i * M;
    int curr = x - 1 < 0 ? 0 : zeroes[x-1];
    curr += back[x] + 1;
    best = min(best, curr);
  }
  best = min(best, zeroes[n-1]);
  return best;
}

// BEGIN CUT HERE
namespace moj_harness {
  int run_test_case(int);
  void run_test(int casenum = -1, bool quiet = false) {
    if (casenum != -1) {
      if (run_test_case(casenum) == -1 && !quiet) {
        cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
      }
      return;
    }

    int correct = 0, total = 0;
    for (int i=0;; ++i) {
      int x = run_test_case(i);
      if (x == -1) {
        if (i >= 100) break;
        continue;
      }
      correct += x;
      ++total;
    }

    if (total == 0) {
      cerr << "No test cases run." << endl;
    } else if (correct < total) {
      cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
    } else {
      cerr << "All " << total << " tests passed!" << endl;
    }
  }

  int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
    cerr << "Example " << casenum << "... "; 

    string verdict;
    vector<string> info;
    char buf[100];

    if (elapsed > CLOCKS_PER_SEC / 200) {
      sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
      info.push_back(buf);
    }

    if (expected == received) {
      verdict = "PASSED";
    } else {
      verdict = "FAILED";
    }

    cerr << verdict;
    if (!info.empty()) {
      cerr << " (";
      for (int i=0; i<(int)info.size(); ++i) {
        if (i > 0) cerr << ", ";
        cerr << info[i];
      }
      cerr << ")";
    }
    cerr << endl;

    if (verdict == "FAILED") {
      cerr << "    Expected: " << expected << endl; 
      cerr << "    Received: " << received << endl; 
    }

    return verdict == "PASSED";
  }

  int run_test_case(int casenum__) {
    switch (casenum__) {
      case 0: {
                string S[]                = {"00111000"};
                int M                     = 1;
                int expected__            = 2;

                clock_t start__           = clock();
                int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                string S[]                = {"00111000"};
                int M                     = 2;
                int expected__            = 3;

                clock_t start__           = clock();
                int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                string S[]                = {"111111"};
                int M                     = 3;
                int expected__            = 0;

                clock_t start__           = clock();
                int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                string S[]                = {"00100"};
                int M                     = 5;
                int expected__            = 2;

                clock_t start__           = clock();
                int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                string S[]                = {"00010","11010110","1010111","110001010","0110001100"
                  ,"000110110","011010101","00","111","100"}
                ;
                int M                     = 13;
                int expected__            = 31;

                clock_t start__           = clock();
                int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      string S[]                = ;
                      int M                     = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      string S[]                = ;
                      int M                     = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      string S[]                = ;
                      int M                     = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = FlippingBitsDiv2().getmin(vector <string>(S, S + (sizeof S / sizeof S[0])), M);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
      default:
              return -1;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    moj_harness::run_test();
  } else {
    for (int i=1; i<argc; ++i)
      moj_harness::run_test(atoi(argv[i]));
  }
}
// END CUT HERE

