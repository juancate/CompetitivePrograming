// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Jiro has a rectangular board, divided into a grid of square cells.
Each cell in the grid contains either the character '0', or the character '1'.
The vector <string> board contains the current state of the board.
The j-th character of the i-th element of board is the character in row i, column j of the grid.

Jiro now has to make exactly two flips.
In the first flip, he must pick a row and flip all characters in that row.
(When flipped, a '0' turns to a '1' and vice versa.)
In the second flip, he must pick a column and flip all characters in that column.

You are given the vector <string> board.
Return the maximum number of '1's in the grid after Jiro makes the two flips.

DEFINITION
Class:XorBoardDivTwo
Method:theMax
Parameters:vector <string>
Returns:int
Method signature:int theMax(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain the same number of characters.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each character in board will be '0' or '1'.


EXAMPLES

0)
{"101",
 "010",
 "101"}

Returns: 9

Jiro can obtain 9 '1's by flipping the center row and then the center column.

1)
{"111",
 "111",
 "111"}

Returns: 5

Jiro has to make both flips, even if that decreases the number of '1's.

2)
{"0101001",
 "1101011"}

Returns: 9



3)
{"000",
 "001",
 "010",
 "011",
 "100",
 "101",
 "110",
 "111"}

Returns: 15



4)
{"000000000000000000000000",
 "011111100111111001111110",
 "010000000100000001000000",
 "010000000100000001000000",
 "010000000100000001000000",
 "011111100111111001111110",
 "000000100000001000000010",
 "000000100000001000000010",
 "000000100000001000000010",
 "011111100111111001111110",
 "000000000000000000000000"}


Returns: 105



*/
// END CUT HERE
#line 95 "XorBoardDivTwo.cpp"

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

class XorBoardDivTwo {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int n, m;

    void flip_row(vector<string> & b, int r) {
        REP(j, 0, m) {
            if(b[r][j] == '0')
                b[r][j] = '1';
            else
                b[r][j] = '0';
        }
    }

    void flip_col(vector<string> & b, int c) {
        REP(i, 0, n) {
            if(b[i][c] == '0')
                b[i][c] = '1';
            else
                b[i][c] = '0';
        }
    }

    int count_ones(vector<string> board) {
        int ans = 0;
        REP(i, 0, n) REP(j, 0, m) ans += (board[i][j] == '1');

        return ans;
    }

    int theMax(vector <string> board) {
        n = board.size();
        m = board[0].size();

        int ans = 0;

        REP(i, 0, n) {
            vector<string> current = board;

            flip_row(current, i);

            REP(j, 0, m) {
                vector<string> current_col = current;

                flip_col(current_col, j);

                int c = count_ones(current_col);
                ans = max(ans, c);
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
			string board[]            = {"101",
 "010",
 "101"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"111",
 "111",
 "111"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"0101001",
 "1101011"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"000",
 "001",
 "010",
 "011",
 "100",
 "101",
 "110",
 "111"};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"000000000000000000000000",
 "011111100111111001111110",
 "010000000100000001000000",
 "010000000100000001000000",
 "010000000100000001000000",
 "011111100111111001111110",
 "000000100000001000000010",
 "000000100000001000000010",
 "000000100000001000000010",
 "011111100111111001111110",
 "000000000000000000000000"}
;
			int expected__            = 105;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
