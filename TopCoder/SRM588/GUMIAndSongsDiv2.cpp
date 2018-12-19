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

class GUMIAndSongsDiv2 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int maxSongs(vector <int> duration, vector <int> tone, int T);
};


int GUMIAndSongsDiv2::maxSongs(vector <int> duration, vector <int> tone, int T) {
  int n = duration.size();

  int best = 0;

  for (int subset = 1; subset < (1 << n); subset++) {
    int max_tone = -INF, min_tone = INF, sum = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
      if (subset & (1 << i)) {
        max_tone = max(max_tone, tone[i]);
        min_tone = min(min_tone, tone[i]);
        sum += duration[i];
        cnt++;
      }
    }

    if (sum + max_tone - min_tone <= T)
      best = max(best, cnt);
  }

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
                int duration[]            = {3, 5, 4, 11};
                int tone[]                = {2, 1, 3, 1};
                int T                     = 17;
                int expected__            = 3;

                clock_t start__           = clock();
                int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int duration[]            = {100, 200, 300};
                int tone[]                = {1, 2, 3};
                int T                     = 10;
                int expected__            = 0;

                clock_t start__           = clock();
                int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int duration[]            = {1, 2, 3, 4};
                int tone[]                = {1, 1, 1, 1};
                int T                     = 100;
                int expected__            = 4;

                clock_t start__           = clock();
                int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int duration[]            = {10, 10, 10};
                int tone[]                = {58, 58, 58};
                int T                     = 30;
                int expected__            = 3;

                clock_t start__           = clock();
                int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int duration[]            = {8, 11, 7, 15, 9, 16, 7, 9};
                int tone[]                = {3, 8, 5, 4, 2, 7, 4, 1};
                int T                     = 14;
                int expected__            = 1;

                clock_t start__           = clock();
                int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 5: {
                int duration[]            = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
                int tone[]                = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
                int T                     = 302606;
                int expected__            = 8;

                clock_t start__           = clock();
                int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 6: {
                      int duration[]            = ;
                      int tone[]                = ;
                      int T                     = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int duration[]            = ;
                      int tone[]                = ;
                      int T                     = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 8: {
                      int duration[]            = ;
                      int tone[]                = ;
                      int T                     = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
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

