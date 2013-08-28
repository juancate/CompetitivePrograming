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

class KeyDungeonDiv2 {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys);
};

int KeyDungeonDiv2::countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
  int n = doorR.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int r = max(0, doorR[i]-keys[0]);
    int g = max(0, doorG[i]-keys[1]);
    int diff = r+g;
    if (diff <= keys[2])
      ans++;
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
                int doorR[]               = {2, 0, 5, 3};
                int doorG[]               = {1, 4, 0, 2};
                int keys[]                = {2, 3, 1};
                int expected__            = 3;

                clock_t start__           = clock();
                int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int doorR[]               = {0, 1, 2, 0};
                int doorG[]               = {0, 2, 3, 1};
                int keys[]                = {0, 0, 0};
                int expected__            = 1;

                clock_t start__           = clock();
                int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int doorR[]               = {3, 5, 4, 2, 8};
                int doorG[]               = {4, 2, 3, 8, 1};
                int keys[]                = {0, 0, 10};
                int expected__            = 5;

                clock_t start__           = clock();
                int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int doorR[]               = {4, 5, 4, 6, 8};
                int doorG[]               = {2, 1, 2, 3, 5};
                int keys[]                = {1, 2, 1};
                int expected__            = 0;

                clock_t start__           = clock();
                int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int doorR[]               = {41,44,41,57,58,74,84,100,58,2,43,32,82,97,44,13,35,98,96,81,43,77,18,51,27, 27,39,39,45,82,59,20,28,93,6,39,64,78,28,85,17,56,3,68,4,0,36,80,41,77};
                int doorG[]               = {67,15,53,36,88,29,26,57,68,99,97,27,51,70,3,49,65,75,35,92,66,0,23,96,38,86, 98,31,26,75,30,2,92,78,100,99,38,26,85,74,77,15,16,48,100,88,55,93,99,54};
                int keys[]                = {39,31,34};
                int expected__            = 17;

                clock_t start__           = clock();
                int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      int doorR[]               = ;
                      int doorG[]               = ;
                      int keys[]                = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int doorR[]               = ;
                      int doorG[]               = ;
                      int keys[]                = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int doorR[]               = ;
                      int doorG[]               = ;
                      int keys[]                = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = KeyDungeonDiv2().countDoors(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
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

