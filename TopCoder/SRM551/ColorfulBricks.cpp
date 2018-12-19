// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Beaver Bindu has some colored bricks.
Each color is described by an uppercase letter.
Bricks of each color all look exactly the same.
You are given a string bricks.
Each character of bricks represents the color of one of Bindu's bricks.



Bindu wants to arrange all her bricks into a row.
A row of bricks is nice if there is at most one pair of adjacent bricks which have different colors.


Return the number of ways in which Bindu can form a nice row, using all her bricks.
(Two ways are considered identical if they correspond to the same sequence of brick colors.)




DEFINITION
Class:ColorfulBricks
Method:countLayouts
Parameters:string
Returns:int
Method signature:int countLayouts(string bricks)


CONSTRAINTS
-bricks will contain between 1 and 50 characters, inclusive.
-Each character of bricks will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
"ABAB"

Returns: 2

There are six possible ways to arrange all the bricks into a row: "AABB", "ABAB", "ABBA", "BAAB", "BABA" and "BBAA". Out of these, only "AABB" and "BBAA" have at most one pair of adjacent bricks with different colors.

1)
"AAA"

Returns: 1

In this test case, all bricks have the same color. Hence, there is only one way to arrange them into a row. That row is nice, because it has no adjacent bricks of different colors.

2)
"WXYZ"

Returns: 0

Since all four bricks are of different colors, the bricks at positions 0 and 1 will have different colors. Similarly, the bricks at positions 1 and 2 will also have different colors. Hence, no matter how the bricks are arranged in a row, the row will not be nice.

*/
// END CUT HERE
#line 61 "ColorfulBricks.cpp"

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

class ColorfulBricks {
public:
    int countLayouts(string bricks) {
        sort(ALL(bricks));
        int n = (int)bricks.size();
        int diff = 0, cnt = 0;
        REP(i, 0, n-1) {
            if(bricks[i] != bricks[i+1])
                diff++;
        }

        if(diff > 1) return 0;
        if(diff == 0) return 1;
        if(diff == 1) cnt++;

        reverse(ALL(bricks));
        diff = 0;
        REP(i, 0, n-1) {
            if(bricks[i] != bricks[i+1])
                diff++;
        }
        if(diff > 1) return 0;
        cnt++;
        return cnt;
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
			string bricks             = "ABAB";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulBricks().countLayouts(bricks);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string bricks             = "AAA";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColorfulBricks().countLayouts(bricks);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string bricks             = "WXYZ";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ColorfulBricks().countLayouts(bricks);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 3: {
			string bricks             = "ZZBB";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulBricks().countLayouts(bricks);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 4: {
			string bricks             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulBricks().countLayouts(bricks);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string bricks             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulBricks().countLayouts(bricks);
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
