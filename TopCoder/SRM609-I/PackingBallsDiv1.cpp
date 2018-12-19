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

class PackingBallsDiv1 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int minPacks(int K, int A, int B, int C, int D);
};

long long x[100010];

int PackingBallsDiv1::minPacks(int K, int A, int B, int C, int D) {
  x[0] = A;
  for (int i = 1; i < K; i++)
    x[i] = (x[i-1] * B + C) % D + 1;

  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += x[i] / K;
    x[i] %= K;
  }

  sort(x, x+K);
  int best = INF;
  for (int i = 0; i < K; i++)
    best = min(best, (int)x[i] + (K - i - 1));

  ans += best;
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

  int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
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
                int K                     = 3;
                int A                     = 4;
                int B                     = 2;
                int C                     = 5;
                int D                     = 6;
                int expected__            = 4;

                std::clock_t start__      = std::clock();
                int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int K                     = 1;
                int A                     = 58;
                int B                     = 23;
                int C                     = 39;
                int D                     = 93;
                int expected__            = 58;

                std::clock_t start__      = std::clock();
                int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int K                     = 23;
                int A                     = 10988;
                int B                     = 5573;
                int C                     = 4384;
                int D                     = 100007;
                int expected__            = 47743;

                std::clock_t start__      = std::clock();
                int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int K                     = 100000;
                int A                     = 123456789;
                int B                     = 234567890;
                int C                     = 345678901;
                int D                     = 1000000000;
                int expected__            = 331988732;

                std::clock_t start__      = std::clock();
                int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 4: {
                      int K                     = ;
                      int A                     = ;
                      int B                     = ;
                      int C                     = ;
                      int D                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 5: {
                      int K                     = ;
                      int A                     = ;
                      int B                     = ;
                      int C                     = ;
                      int D                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int K                     = ;
                      int A                     = ;
                      int B                     = ;
                      int C                     = ;
                      int D                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
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
