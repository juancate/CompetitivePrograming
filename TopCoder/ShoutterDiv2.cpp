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

class ShoutterDiv2 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int count(vector <int> s, vector <int> t);
};

int ShoutterDiv2::count(vector <int> s, vector <int> t) {
  int n = s.size();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if ((s[i] <= s[j] && s[j] <= t[i]) || (s[j] <= s[i] && s[i] <= t[j]))
        ans++;
    }
  }

  return ans;
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
                int s[]                   = {1, 2, 4};
                int t[]                   = {3, 4, 6};
                int expected__            = 2;

                clock_t start__           = clock();
                int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int s[]                   = {0};
                int t[]                   = {100};
                int expected__            = 0;

                clock_t start__           = clock();
                int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int s[]                   = {0,0,0};
                int t[]                   = {1,1,1};
                int expected__            = 3;

                clock_t start__           = clock();
                int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int s[]                   = {9,26,8,35,3,58,91,24,10,26,22,18,15,12,15,27,15,60,76,19,12,16,37,35,25,4,22,47,65,3,2,23,26,33,7,11,34,74,67,32,15,45,20,53,60,25,74,13,44,51};
                int t[]                   = {26,62,80,80,52,83,100,71,20,73,23,32,80,37,34,55,51,86,97,89,17,81,74,94,79,85,77,97,87,8,70,46,58,70,97,35,80,76,82,80,19,56,65,62,80,49,79,28,75,78};
                int expected__            = 830;

                clock_t start__           = clock();
                int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 4: {
                      int s[]                   = ;
                      int t[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 5: {
                      int s[]                   = ;
                      int t[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int s[]                   = ;
                      int t[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = ShoutterDiv2().count(vector <int>(s, s + (sizeof s / sizeof s[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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

