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

class GeometricProgressions {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int count(int b1, int q1, int n1, int b2, int q2, int n2);
};

void factor(int q, set<int>& f) {
  for(int p = 2; p*p <= q; p++) {
    if(q % p == 0) {
      while(q % p == 0)
        q /= p;
      f.insert(p);
    }
  }

  if(q > 1)
    f.insert(q);
}

void decompose(int q, vector<int>& rep, const vector<int>& F) {
  for(int i = 0; i < F.size(); i++) {
    int cnt = 0;

    while(q % F[i] == 0) {
      q /= F[i];
      cnt++;
    }

    rep.push_back(cnt);
  }
}

int GeometricProgressions::count(int b1, int q1, int n1, int b2, int q2, int n2) {
  if(b2 == 0 || q2 <= 1) {
    swap(b1, b2); swap(q1, q2); swap(n1, n2);
  }

  if(b1 == 0 || q1 <= 1) {
    set<long long> S;
    S.insert(b1);
    if(n1 > 1)
      S.insert(b1*q1);

    long long curr = b2;
    for(int i = 0; i < n2; i++) {
      S.insert(curr);
      curr *= q2;

      if(curr > 500000000)
        return (n2 - i - 1) + S.size();
    }
    return S.size();
  }

  set<int> factors;
  factor(b1, factors); factor(q1, factors);
  factor(b2, factors); factor(q2, factors);

  vector<int> F(ALL(factors));
  vector<int> repb1, repq1, repb2, repq2;

  decompose(b1, repb1, F); decompose(q1, repq1, F);
  decompose(b2, repb2, F); decompose(q2, repq2, F);

  set< vector<int> > S;

  for(int i = 1; i <= n1; i++) {
    S.insert(repb1);
    for(int j = 0; j < repb1.size(); j++)
      repb1[j] += repq1[j];
  }

  for(int i = 1; i <= n2; i++) {
    S.insert(repb2);
    for(int j = 0; j < repb2.size(); j++)
      repb2[j] += repq2[j];
  }

  return S.size();
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
                int b1                    = 3;
                int q1                    = 2;
                int n1                    = 5;
                int b2                    = 6;
                int q2                    = 2;
                int n2                    = 5;
                int expected__            = 6;

                clock_t start__           = clock();
                int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int b1                    = 3;
                int q1                    = 2;
                int n1                    = 5;
                int b2                    = 2;
                int q2                    = 3;
                int n2                    = 5;
                int expected__            = 9;

                clock_t start__           = clock();
                int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int b1                    = 1;
                int q1                    = 1;
                int n1                    = 1;
                int b2                    = 0;
                int q2                    = 0;
                int n2                    = 1;
                int expected__            = 2;

                clock_t start__           = clock();
                int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int b1                    = 3;
                int q1                    = 4;
                int n1                    = 100500;
                int b2                    = 48;
                int q2                    = 1024;
                int n2                    = 1000;
                int expected__            = 100500;

                clock_t start__           = clock();
                int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

                    case 4: {
                      int b1                    = 2;
                      int q1                    = 4;
                      int n1                    = 28746;
                      int b2                    = 1;
                      int q2                    = 6;
                      int n2                    = 31674;
                      int expected__            = 60420;

                      clock_t start__           = clock();
                      int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }
              /*      case 5: {
                      int b1                    = ;
                      int q1                    = ;
                      int n1                    = ;
                      int b2                    = ;
                      int q2                    = ;
                      int n2                    = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int b1                    = ;
                      int q1                    = ;
                      int n1                    = ;
                      int b2                    = ;
                      int q2                    = ;
                      int n2                    = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
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

