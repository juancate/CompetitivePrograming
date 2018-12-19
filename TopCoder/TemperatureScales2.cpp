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

class TemperatureScales2 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    double convert(int f1, int b1, int f2, int b2, int t);
};


double TemperatureScales2::convert(int f1, int b1, int f2, int b2, int t) {
  double a = (double)(b2-f2)/(double)(b1-f1);

  double b = f2-a*f1;
  double ans = a*t + b;

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

  static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
  double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

  int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
    cerr << "Example " << casenum << "... "; 

    string verdict;
    vector<string> info;
    char buf[100];

    if (elapsed > CLOCKS_PER_SEC / 200) {
      sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
      info.push_back(buf);
    }

    if (topcoder_fequ(expected, received)) {
      verdict = "PASSED";
      double rerr = moj_relative_error(expected, received); 
      if (rerr > 0) {
        sprintf(buf, "relative error %.3e", rerr);
        info.push_back(buf);
      }
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
                int f1                    = 0;
                int b1                    = 100;
                int f2                    = 0;
                int b2                    = 100;
                int t                     = 28;
                double expected__         = 28.0;

                clock_t start__           = clock();
                double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int f1                    = 0;
                int b1                    = 100;
                int f2                    = 1;
                int b2                    = 101;
                int t                     = 28;
                double expected__         = 29.0;

                clock_t start__           = clock();
                double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int f1                    = -1000;
                int b1                    = -999;
                int f2                    = -1000;
                int b2                    = 1000;
                int t                     = 1000;
                double expected__         = 3999000.0;

                clock_t start__           = clock();
                double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int f1                    = -10;
                int b1                    = 0;
                int f2                    = 1;
                int b2                    = 2;
                int t                     = 17;
                double expected__         = 3.7;

                clock_t start__           = clock();
                double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int f1                    = 17;
                int b1                    = 98;
                int f2                    = -123;
                int b2                    = 12;
                int t                     = 22;
                double expected__         = -114.66666666666667;

                clock_t start__           = clock();
                double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      int f1                    = ;
                      int b1                    = ;
                      int f2                    = ;
                      int b2                    = ;
                      int t                     = ;
                      double expected__         = ;

                      clock_t start__           = clock();
                      double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int f1                    = ;
                      int b1                    = ;
                      int f2                    = ;
                      int b2                    = ;
                      int t                     = ;
                      double expected__         = ;

                      clock_t start__           = clock();
                      double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int f1                    = ;
                      int b1                    = ;
                      int f2                    = ;
                      int b2                    = ;
                      int t                     = ;
                      double expected__         = ;

                      clock_t start__           = clock();
                      double received__         = TemperatureScales2().convert(f1, b1, f2, b2, t);
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

