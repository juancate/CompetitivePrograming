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

class EnclosingTriangleColorful {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int getNumber(int m, vector <int> x, vector <int> y);
};

struct point {
  int x, y;
  point(int _x=0, int _y=0) {
    x = _x;
    y = _y;
  }
};

int n;
vector<int> X, Y;

vector<point> mat[4][4];

int cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

int prod(int xx1, int yy1, int xx2, int yy2, int xb, int yb) {
  return cross(point(xx1,yy1), point(xx2, yy2), point(xb,yb));
}

int solve() {
  int ans = 0;
  for (int xx = 1; xx <= n-1; xx++) {
    for (int yy = 1; yy <= n-1; yy++) {
      bool p12 = true, p23 = true, p34 = true, p41 = true, p13 = true, p24 = true;
      for (int i = 0; i < X.size(); i++) {
        int p1 = prod(xx, 0, n, yy, X[i], Y[i]); // red to green
        int p2 = prod(n, yy, xx, n, X[i], Y[i]); // green to blue
        int p3 = prod(xx, n, 0, yy, X[i], Y[i]); // blue to yellow
        int p4 = prod(0, yy, xx, 0, X[i], Y[i]); // yellow to red

        int p5 = prod(xx, 0, xx, n, X[i], Y[i]); // red to blue
        int p6 = prod(0, yy, n, yy, X[i], Y[i]); // yellow to green
        if (p1 < 0) p12 = false;
        if (p2 < 0) p23 = false;
        if (p3 > 0) p34 = false;
        if (p4 > 0) p41 = false;

        if (p5 < 0) p13 = false;
        if (p6 > 0) p24 = false;
      }
      if (p12) mat[0][1].push_back(point(xx,yy));
    }
  }

  return ans;
}

int EnclosingTriangleColorful::getNumber(int m, vector <int> x, vector <int> y) {
  n = m;
  X = x;
  Y = y;

  return solve();
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
                int m                     = 4;
                int x[]                   = { 1, 2, 3 };
                int y[]                   = { 1, 3, 2 };
                int expected__            = 8;

                clock_t start__           = clock();
                int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int m                     = 7;
                int x[]                   = { 1, 1, 6, 6 };
                int y[]                   = { 1, 6, 1, 6 };
                int expected__            = 0;

                clock_t start__           = clock();
                int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int m                     = 4;
                int x[]                   = { 2 };
                int y[]                   = { 2 };
                int expected__            = 72;

                clock_t start__           = clock();
                int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int m                     = 10;
                int x[]                   = { 2, 6, 7, 6 };
                int y[]                   = { 7, 7, 9, 3 };
                int expected__            = 52;

                clock_t start__           = clock();
                int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int m                     = 15;
                int x[]                   = { 7, 6, 5, 4, 3 };
                int y[]                   = { 1, 4, 7, 10, 13 };
                int expected__            = 150;

                clock_t start__           = clock();
                int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 5: {
                int m                     = 300;
                int x[]                   = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 137, 177, 125, 123, 172, 125, 137, 143, 120, 178 } ;
                int y[]                   = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 118, 122, 179, 122, 180, 121, 182, 183, 128, 177 } ;
                int expected__            = 21690886;

                clock_t start__           = clock();
                int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 6: {
                      int m                     = ;
                      int x[]                   = ;
                      int y[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int m                     = ;
                      int x[]                   = ;
                      int y[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 8: {
                      int m                     = ;
                      int x[]                   = ;
                      int y[]                   = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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

