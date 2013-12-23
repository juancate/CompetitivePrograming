#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int INF = int(1e9);
// BEGIN CUT HERE
#define D(x) cerr << #x << " = " << x << endl;
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  for (int i = 0; i < z.size(); i++)os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; foreach(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; foreach(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class WinterAndPresents {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    long long getNumber(vector <int> apple, vector <int> orange);
};

long long WinterAndPresents::getNumber(vector <int> apple, vector <int> orange) {
  int n = apple.size();

  int limit = INF;
  for (int i = 0; i < n; i++)
    limit = min(limit, apple[i]+orange[i]);

  long long ans = 0;

  for (int X = 1; X <= limit; X++) {
    long long l = 0, h = 0;
    for (int i = 0; i < n; i++) {
      l += max(0, X - orange[i]);
      h += min(apple[i], X);
    }

    ans += h - l + 1;
  }

  return ans;
}
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
  using std::string;
  using std::vector;
  int run_test_case(int);
  void run_test(int casenum = -1, bool quiet = false) {
    if (casenum != -1) {
      if (run_test_case(casenum) == -1 && !quiet) {
        std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
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
      std::cerr << "No test cases run." << std::endl;
    } else if (correct < total) {
      std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
    } else {
      std::cerr << "All " << total << " tests passed!" << std::endl;
    }
  }

  int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) {
    std::cerr << "Example " << casenum << "... ";

    string verdict;
    vector<string> info;
    char buf[100];

    if (elapsed > CLOCKS_PER_SEC / 200) {
      std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
      info.push_back(buf);
    }

    if (expected == received) {
      verdict = "PASSED";
    } else {
      verdict = "FAILED";
    }

    std::cerr << verdict;
    if (!info.empty()) {
      std::cerr << " (";
      for (size_t i=0; i<info.size(); ++i) {
        if (i > 0) std::cerr << ", ";
        std::cerr << info[i];
      }
      std::cerr << ")";
    }
    std::cerr << std::endl;

    if (verdict == "FAILED") {
      std::cerr << "    Expected: " << expected << std::endl;
      std::cerr << "    Received: " << received << std::endl;
    }

    return verdict == "PASSED";
  }

  int run_test_case(int casenum__) {
    switch (casenum__) {
      case 0: {
                int apple[]               = {1};
                int orange[]              = {1};
                long long expected__      = 3;

                std::clock_t start__      = std::clock();
                long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int apple[]               = {1, 2, 0, 3};
                int orange[]              = {4, 5, 0, 6};
                long long expected__      = 0;

                std::clock_t start__      = std::clock();
                long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int apple[]               = {2, 2, 2};
                int orange[]              = {2, 2, 2};
                long long expected__      = 16;

                std::clock_t start__      = std::clock();
                long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int apple[]               = {7, 4, 5};
                int orange[]              = {1, 10, 2};
                long long expected__      = 46;

                std::clock_t start__      = std::clock();
                long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int apple[]               = {1000000};
                int orange[]              = {1000000};
                long long expected__      = 1000002000000LL;

                std::clock_t start__      = std::clock();
                long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      int apple[]               = ;
                      int orange[]              = ;
                      long long expected__      = ;

                      std::clock_t start__      = std::clock();
                      long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int apple[]               = ;
                      int orange[]              = ;
                      long long expected__      = ;

                      std::clock_t start__      = std::clock();
                      long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int apple[]               = ;
                      int orange[]              = ;
                      long long expected__      = ;

                      std::clock_t start__      = std::clock();
                      long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
      default:
              return -1;
    }
  }
}

#include <cstdlib>
int main(int argc, char *argv[]) {
  if (argc == 1) {
    moj_harness::run_test();
  } else {
    for (int i=1; i<argc; ++i)
      moj_harness::run_test(std::atoi(argv[i]));
  }
}
// END CUT HERE
