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

class TeamContestEasy {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int worstRank(vector <int> strength);
};

int TeamContestEasy::worstRank(vector <int> strength) {
  int n = strength.size();

  if(n == 3) {
    return 1;
  }

  vector<int> rivals(n-3);
  vector<bool> used(n-3, false);
  for(int i = 3; i < n; i++) {
    rivals[i-3] = strength[i];
  }

  int s = strength[0] + strength[1] + strength[2];
  s -= min(strength[0], min(strength[1], strength[2]));
  sort(rivals.begin(), rivals.end(), greater<int>());

  int last = rivals.size()-1;
  int N = n / 3;
  vector<int> teams(N-1);
  for(int i = 0, id = 0; id < n-3; id++) {
    if(!used[id]) {
      int d = s-rivals[id];
      teams[i] += rivals[id];
      used[id] = true;

      if(d < 0) {
        if(last < 0) last = rivals.size()-1;
        while(last > 0 && used[last])
          last--;
        assert(last >= 0);
        teams[i] += rivals[last];
        used[last] = true;
        last--;
      }
      else {
        int v = d + 1;
        int j = int(upper_bound(rivals.begin(), rivals.end(), v, greater<int>()) - rivals.begin());
        if(j == N-1) j--;
        while(j > 0 && (rivals[j] < v || used[j]))
          j--;
        if(!used[j]) {
          teams[i] += rivals[j];
          used[j] = true;
        }
        else {
          if(last < 0) last = rivals.size()-1;
          while(last > 0 && used[last])
            last--;
          assert(last >= 0);
          teams[i] += rivals[last];
          used[last] = true;
          last--;
        }
      }
      if(last < 0) last = rivals.size()-1;
      while(last > 0 && used[last])
        last--;
      used[last] = true;
      last--;
      i++;
    }
  }

  sort(teams.begin(), teams.end(), greater<int>());

  int pos = int(lower_bound(teams.begin(), teams.end(), s, greater<int>()) - teams.begin());
  return pos+1;
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
                int strength[]            = {5, 7, 3, 5, 7, 3, 5, 7, 3};
                int expected__            = 2;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int strength[]            = {5, 7, 3};
                int expected__            = 1;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int strength[]            = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
                int expected__            = 1;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int strength[]            = {2,2,1,1,3,1,3,2,1,3,1,2,1,2,1} ;
                int expected__            = 4;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int strength[]            = {45,72,10,42,67,51,33,21,8,51,17,72} ;
                int expected__            = 3;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 5: {
                int strength[]            = {570466,958327,816467,17,403,953808,734850,5824,917784,921731,161921,1734,823437,3218,81,932681,2704,981643,1232,475,873323,6558,45660,1813,4714,224, 32301,28081,6728,17055,561,15146,842613,5559,1860,783,989,2811,20664,112531,1933,866794,805528,53821,2465,137385,39,2007};
                int expected__            = 6;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 6: {
                int strength[]            = {610297,849870,523999,6557,976530,731458,7404,795100,147040,110947,159692,40785,4949,2903,1688,37278,620703,28156,16823,1159,12132,971379,5916,1159,988589, 12215,133,1490,911360,920059,544070,40249,514852,852,745070,1105,715897,714696,589133,698317,5683,631612,16453,101000,764881,101,2053,754661};
                int expected__            = 10;

                clock_t start__           = clock();
                int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

                    case 7: {
                      int strength[]            = {1,2,1,2,2,2,2,2,2,1,1,1};
                      int expected__            = 4;

                      clock_t start__           = clock();
                      int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }
                    case 8: {
                      int strength[]            = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 8, 7, 6, 5, 4, 3, 1, 2, 3, 4, 5, 5, 6, 9, 2};
                      int expected__            = 16;

                      clock_t start__           = clock();
                      int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }
              /*      case 9: {
                      int strength[]            = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = TeamContestEasy().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
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

