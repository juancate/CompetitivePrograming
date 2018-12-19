// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Jiro came to a flower shop to buy flowers.
The flowers in the shop are arranged in some cells of a rectangular grid.
The layout of the grid is given as a vector <string> flowers.
If the j-th cell of the i-th row of the grid contains a flower, then the j-th character of the i-th element of flowers will be 'F'.
(All indices in the previous sentence are 0-based.)
If the particular cell is empty, the corresponding character will be '.' (a period).

In order to buy flowers, Jiro has to draw a rectangle on this grid and buy all the flowers which lie inside the rectangle.
Of course, the sides of the rectangle must be on cell boundaries.
(Therefore, the sides of the rectangle will necessarily be parallel to the coordinate axes.)

Jiro wants to buy as many flowers as possible.
Unfortunately, he cannot select the entire grid.
Eel Saburo came to this shop before Jiro.
Saburo has already drawn his rectangle.
Saburo's rectangle contains just a single cell: the c-th cell of the r-th row of the grid.
(Again, both indices are 0-based.)
Jiro's rectangle may not contain this cell.

You are given the vector <string> flowers and the ints r and c.
Return the maximum possible number of flowers Jiro can buy in this situation.

DEFINITION
Class:FoxAndFlowerShopDivTwo
Method:theMaxFlowers
Parameters:vector <string>, int, int
Returns:int
Method signature:int theMaxFlowers(vector <string> flowers, int r, int c)


CONSTRAINTS
-flowers will contain R elements.
-R will be between 2 and 10, inclusive.
-Each element of flowers will contain C characters.
-C will be between 1 and 10, inclusive.
-Each character in flowers will be either 'F' or '.'.
-r will be between 0 and R - 1, inclusive.
-c will be between 0 and C - 1, inclusive.


EXAMPLES

0)
{"F.F",
 ".F.",
 ".F."}
1
1

Returns: 2

The forbidden cell is the one in the middle. Jiro can buy two flowers by drawing a rectangle that contains the entire first row.

1)
{"F..",
 "...",
 "..."}
0
0

Returns: 0

There are no flowers Jiro can buy.

2)
{".FF.F.F",
 "FF...F.",
 "..FF.FF"}
1
2

Returns: 6



3)
{"F",
 ".",
 "F",
 "F",
 "F",
 ".",
 "F",
 "F"}
4
0

Returns: 3



4)
{".FFF..F...",
 "FFF...FF.F",
 "..F.F.F.FF",
 "FF..F.FFF.",
 "..FFFFF...",
 "F....FF...",
 ".FF.FF..FF",
 "..F.F.FFF.",
 ".FF..F.F.F",
 "F.FFF.FF.F"}
4
3

Returns: 32



*/
// END CUT HERE
#line 116 "FoxAndFlowerShopDivTwo.cpp"

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

class FoxAndFlowerShopDivTwo {
public:
    int theMaxFlowers(vector <string> flowers, int r, int c) {
        int n = flowers.size();
        int m = flowers[0].size();

        int cnt = 0, ans = -1;

        REP(i, 0, r) {
            REP(j, 0, m) {
                cnt += (flowers[i][j] == 'F');
            }
        }
        ans = max(ans, cnt);

        cnt = 0;
        REP(i, r+1, n) {
            REP(j, 0, m) {
                cnt += (flowers[i][j] == 'F');
            }
        }
        ans = max(ans, cnt);

        cnt = 0;
        REP(i, 0, n) {
            REP(j, 0, c) {
                cnt += (flowers[i][j] == 'F');
            }
        }
        ans = max(ans, cnt);

        cnt = 0;
        REP(i, 0, n) {
            REP(j, c+1, m) {
                cnt += (flowers[i][j] == 'F');
            }
        }
        ans = max(ans, cnt);
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
			string flowers[]          = {"F.F",
 ".F.",
 ".F."};
			int r                     = 1;
			int c                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string flowers[]          = {"F..",
 "...",
 "..."};
			int r                     = 0;
			int c                     = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string flowers[]          = {".FF.F.F",
 "FF...F.",
 "..FF.FF"};
			int r                     = 1;
			int c                     = 2;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string flowers[]          = {"F",
 ".",
 "F",
 "F",
 "F",
 ".",
 "F",
 "F"};
			int r                     = 4;
			int c                     = 0;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string flowers[]          = {".FFF..F...",
 "FFF...FF.F",
 "..F.F.F.FF",
 "FF..F.FFF.",
 "..FFFFF...",
 "F....FF...",
 ".FF.FF..FF",
 "..F.F.FFF.",
 ".FF..F.F.F",
 "F.FFF.FF.F"};
			int r                     = 4;
			int c                     = 3;
			int expected__            = 32;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string flowers[]          = ;
			int r                     = ;
			int c                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string flowers[]          = ;
			int r                     = ;
			int c                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string flowers[]          = ;
			int r                     = ;
			int c                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndFlowerShopDivTwo().theMaxFlowers(vector <string>(flowers, flowers + (sizeof flowers / sizeof flowers[0])), r, c);
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
