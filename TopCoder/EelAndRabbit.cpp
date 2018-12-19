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

class EelAndRabbit {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int getmax(vector <int> l, vector <int> t);
};

struct segment {
  int left, right;

  segment(int l = 0, int r = 0) {
    left = l, right = r;
  }

  bool operator<(const segment& a) const {
    if(left == a.left)
      return right > a.right;
    return left < a.left;
  }
};

int EelAndRabbit::getmax(vector <int> le, vector <int> t) {
  int n = le.size();
  vector<segment> s(n);
  int T = 0;

  for (int i = 0; i < n; i++)
    s[i] = segment(T-t[i]-le[i], T-t[i]);
  sort(s.begin(), s.end());

  int r = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int best_right = s[i].right;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      best_right = min(best_right, s[j].right);
    }
    for (int j = 0; j < n; j++) {
      if ((s[i].left <= s[j].left && s[j].left <= best_right) ||
          (s[i].left <= s[j].right && s[j].right <= best_right))
        cnt++;
    }
    r = max(cnt, r);
  }
  return r;
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
                int l[]                   = {2, 4, 3, 2, 2, 1, 10};
                int t[]                   = {2, 6, 3, 7, 0, 2, 0};
                int expected__            = 6;

                clock_t start__           = clock();
                int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int l[]                   = {1, 1, 1};
                int t[]                   = {2, 0, 4};
                int expected__            = 2;

                clock_t start__           = clock();
                int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int l[]                   = {1};
                int t[]                   = {1};
                int expected__            = 1;

                clock_t start__           = clock();
                int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int l[]                   = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
                int t[]                   = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
                int expected__            = 7;

                clock_t start__           = clock();
                int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 4: {
                      int l[]                   = ;
                      int t[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 5: {
                      int l[]                   = ;
                      int t[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int l[]                   = ;
                      int t[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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

