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

class ThreeColorabilityEasy {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    string isColorable(vector <string> cells);
};

const int maxn = 55;

int color[maxn][maxn];

bool paintTriangle(int& a, int& b, int& c) {
  if (a == -1 || b == -1)
    return paintTriangle(c, a, b);
  if (c != -1)
    return (a == b || a == c || b == c);
  c = 0;
  while ((a == c || b == c) && (c < 2))
    c++;
  return a == b;
}

bool paintTwoTriangles(int& a, int& b, int& c, int& d) {
  if (a == -1 && b == -1 && c == -1 && d == -1) {
    a = 0, b = c = 1, d = 2;
    return false;
  }

  int unknown = ((a == -1) + (b == -1) + (d == -1));
  if (unknown > 1)
    return paintTwoTriangles(a, c, b, d);
  return paintTriangle(a, b, d) || paintTriangle(a, c, d);
}

string ThreeColorabilityEasy::isColorable(vector <string> cells) {
  memset(color, -1, sizeof(color));

  int H = cells.size();
  int W = cells[0].size();

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int& a = color[i][j]; int& b = color[i][j+1];
      int& c = color[i+1][j]; int& d = color[i+1][j+1];

      bool cont = false;

      if (cells[i][j] == 'N')
        cont = paintTwoTriangles(a, b, c, d);
      else
        cont = paintTwoTriangles(b, a, d, c);

      if (cont)
        return "No";
    }
  }

  return "Yes";
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

  int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
      cerr << "    Expected: \"" << expected << "\"" << endl; 
      cerr << "    Received: \"" << received << "\"" << endl; 
    }

    return verdict == "PASSED";
  }

  int run_test_case(int casenum__) {
    switch (casenum__) {
      case 0: {
                string cells[]            = {"Z"};
                string expected__         = "Yes";

                clock_t start__           = clock();
                string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                string cells[]            = {"NZ"
                  ,"NZ"};
                string expected__         = "Yes";

                clock_t start__           = clock();
                string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                string cells[]            = {"ZZZ"
                  ,"ZNZ"};
                string expected__         = "No";

                clock_t start__           = clock();
                string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                string cells[]            = {"NZNZNNN"
                  ,"NNZNNNZ"
                    ,"NNNNZZZ"
                    ,"ZZZNZZN"
                    ,"ZZNZNNN"
                    ,"NZZZZNN"
                    ,"ZZZNZNN"};
                string expected__         = "No";

                clock_t start__           = clock();
                string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                string cells[]            = {"ZZZZ"
                  ,"ZZZZ"
                    ,"ZZZZ"};
                string expected__         = "Yes";

                clock_t start__           = clock();
                string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      string cells[]            = ;
                      string expected__         = ;

                      clock_t start__           = clock();
                      string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      string cells[]            = ;
                      string expected__         = ;

                      clock_t start__           = clock();
                      string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      string cells[]            = ;
                      string expected__         = ;

                      clock_t start__           = clock();
                      string received__         = ThreeColorabilityEasy().isColorable(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
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

