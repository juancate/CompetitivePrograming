// BEGIN CUT HERE
/*
PROBLEM STATEMENT

John and Brus are building towers using toy bricks.
They have two types of bricks: red and blue ones.
The number of red bricks they have is redCount and each of them has a height of redHeight.
The number of blue bricks they have is blueCount and each of them has a height of blueHeight.



A tower is built by placing bricks one atop another.
A brick can be placed either on the ground, or on a brick of a different color.
(I.e., you are not allowed to put two bricks of the same color immediately on one another.)
A tower has to consist of at least one brick.
The height of a tower is the sum of all heights of bricks that form the tower.
Two towers are considered to be different if they have different heights.
(Two towers of the same height are considered the same, even if they differ in the number and colors of bricks that form them.)



You are given the ints redCount, redHeight, blueCount and blueHeight.
Return the number of different towers that John and Brus can build.



DEFINITION
Class:TheBrickTowerEasyDivTwo
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int redCount, int redHeight, int blueCount, int blueHeight)


CONSTRAINTS
-redCount will be between 1 and 47, inclusive.
-redHeight will be between 1 and 47, inclusive.
-blueCount will be between 1 and 47, inclusive.
-blueHeight will be between 1 and 47, inclusive.


EXAMPLES

0)
1
2
3
4

Returns: 4

John and Brus have 1 red brick of height 2 and 3 blue bricks of height 4. Using these bricks, it's possible to build 4 towers:
red (height 2);
blue (height 4);
red, blue (height 6);
blue, red, blue (height 10).

1)
4
4
4
7

Returns: 12



2)
7
7
4
4

Returns: 13



3)
47
47
47
47

Returns: 94



*/
// END CUT HERE
#line 91 "TheBrickTowerEasyDivTwo.cpp"

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

class TheBrickTowerEasyDivTwo {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int find(int redCount, int redHeight, int blueCount, int blueHeight) {
        int ans = (redHeight != blueHeight)? 2 : 1;
        int r = 1;
        for(int i = 2; i < 94; i++) {
            if(i & 1) {
                if(redCount >= i-r) {
                    ans++;
                    if(blueHeight != redHeight && blueCount >= i-r)
                        ans++;
                }
                else if(blueCount >= i-r) {
                    ans++;
                } else {
                    break;
                }
                r++;
            } else {
                if(redCount >= i / 2 && blueCount >= i / 2)
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};

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
			int redCount              = 1;
			int redHeight             = 2;
			int blueCount             = 3;
			int blueHeight            = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int redCount              = 4;
			int redHeight             = 4;
			int blueCount             = 4;
			int blueHeight            = 7;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int redCount              = 7;
			int redHeight             = 7;
			int blueCount             = 4;
			int blueHeight            = 4;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int redCount              = 47;
			int redHeight             = 47;
			int blueCount             = 47;
			int blueHeight            = 47;
			int expected__            = 94;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int redCount              = 47;
			int redHeight             = 46;
			int blueCount             = 47;
			int blueHeight            = 47;
			int expected__            = 140;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 5: {
			int redCount              = 1;
			int redHeight             = 1;
			int blueCount             = 1;
			int blueHeight            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int redCount              = ;
			int redHeight             = ;
			int blueCount             = ;
			int blueHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivTwo().find(redCount, redHeight, blueCount, blueHeight);
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
