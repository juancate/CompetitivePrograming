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

class TheExperimentDiv2 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd);
};

vector <int> TheExperimentDiv2::determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
  int n = intensity.size();
  int m = leftEnd.size();

  vector<int> ans(m);

  for(int i = 0; i < n; i++) {
    double pos = i + 0.5;
    for(int j = 0; j < m; j++) {
      if(leftEnd[j] <= pos && pos <= leftEnd[j]+L) {
        ans[j] += intensity[i];
        break;
      }
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

  template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

  int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
                int intensity[]           = {3, 4, 1, 1, 5, 6};
                int L                     = 3;
                int leftEnd[]             = {3, 1, 0};
                int expected__[]          = {12, 5, 3 };

                clock_t start__           = clock();
                vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 1: {
                int intensity[]           = {5, 5};
                int L                     = 2;
                int leftEnd[]             = {0, 0};
                int expected__[]          = {10, 0 };

                clock_t start__           = clock();
                vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 2: {
                int intensity[]           = {92, 11, 1000, 14, 3};
                int L                     = 2;
                int leftEnd[]             = {0, 3};
                int expected__[]          = {103, 17 };

                clock_t start__           = clock();
                vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 3: {
                int intensity[]           = {2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13};
                int L                     = 4;
                int leftEnd[]             = {1, 7, 4, 5, 8, 0};
                int expected__[]          = {39, 14, 110, 0, 13, 2 };

                clock_t start__           = clock();
                vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }

              // custom cases

              /*      case 4: {
                      int intensity[]           = ;
                      int L                     = ;
                      int leftEnd[]             = ;
                      int expected__[]          = ;

                      clock_t start__           = clock();
                      vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                      return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
              /*      case 5: {
                      int intensity[]           = ;
                      int L                     = ;
                      int leftEnd[]             = ;
                      int expected__[]          = ;

                      clock_t start__           = clock();
                      vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                      return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int intensity[]           = ;
                      int L                     = ;
                      int leftEnd[]             = ;
                      int expected__[]          = ;

                      clock_t start__           = clock();
                      vector <int> received__   = TheExperimentDiv2().determineHumidity(vector <int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector <int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
                      return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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

