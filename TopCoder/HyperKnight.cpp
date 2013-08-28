// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fernando loves to play chess. One day he decided to play chess on an unusually large rectangular board. To compensate for the board's size he also decided to change the distance a knight can move in a single jump.

To describe the moves easily, we will now introduce a coordinate system. Each cell of the chessboard can be described using two integers (r,c): its row number and its column number. Now, if we have a piece at (r,c), the move (x,y) takes the piece to the cell (r+x,c+y).

The new chess piece will be called an (a,b)-hyperknight. The hyperknight always has 8 possible moves: (+a,+b), (+a,-b), (-a,+b), (-a,-b), (+b,+a), (+b,-a), (-b,+a), and (-b,-a). Note that the original chess knight is a (2,1)-hyperknight.

Of course, as the chessboard is finite, it is not always possible to make each of the 8 moves. Some of them may cause our hyperknight to leave the chessboard. A move is called valid if the destination cell is on the chessboard. Fernando would like to know the number of cells on his board such that his hyperknight will have exactly k valid moves from that cell.

You are given the ints a, b, numRows, numColumns and k. The values numRows and numColumns define the number of rows and number of columns on the chessboard, respectively. The other three values were already explained above. Compute and return the number of cells on the chessboard that have exactly k valid (a,b)-hyperknight moves.

DEFINITION
Class:HyperKnight
Method:countCells
Parameters:int, int, int, int, int
Returns:long long
Method signature:long long countCells(int a, int b, int numRows, int numColumns, int k)


NOTES
-If you wish, you may assume that the rows are numbered 0 through numRows-1 and columns 0 through numColumns-1. However, note that the actual row/column numbers do not matter, as long as they are consecutive.


CONSTRAINTS
-a will be between 1 and 1,000,000,000 (10^9), inclusive.
-b will be between 1 and 1,000,000,000 (10^9), inclusive.
-a will not be equal to b.
-numRows will be between 1 and 1,000,000,000 (10^9), inclusive.
-numColumns will be between 1 and 1,000,000,000 (10^9), inclusive.
-2*max(a,b) will be strictly less than min(numRows,numColumns).
-k will be between 0 and 8, inclusive.


EXAMPLES

0)
2
1
8
8
4

Returns: 20

This is a standard chessboard. We have a traditional chess knight and we are looking for cells such that the knight has exactly 4 valid moves.

1)
3
2
8
8
2

Returns: 16



2)
1
3
7
11
0

Returns: 0



3)
3
2
10
20
8

Returns: 56



4)
1
4
100
10
6

Returns: 564



5)
2
3
1000000000
1000000000
8

Returns: 999999988000000036



*/
// END CUT HERE
#line 107 "HyperKnight.cpp"

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

class HyperKnight {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    long long countCells(int a, int b, int numRows, int numColumns, int k) {
        
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int a                     = 2;
			int b                     = 1;
			int numRows               = 8;
			int numColumns            = 8;
			int k                     = 4;
			long long expected__      = 20;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 3;
			int b                     = 2;
			int numRows               = 8;
			int numColumns            = 8;
			int k                     = 2;
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 1;
			int b                     = 3;
			int numRows               = 7;
			int numColumns            = 11;
			int k                     = 0;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 3;
			int b                     = 2;
			int numRows               = 10;
			int numColumns            = 20;
			int k                     = 8;
			long long expected__      = 56;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 1;
			int b                     = 4;
			int numRows               = 100;
			int numColumns            = 10;
			int k                     = 6;
			long long expected__      = 564;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int a                     = 2;
			int b                     = 3;
			int numRows               = 1000000000;
			int numColumns            = 1000000000;
			int k                     = 8;
			long long expected__      = 999999988000000036LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int a                     = ;
			int b                     = ;
			int numRows               = ;
			int numColumns            = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int numRows               = ;
			int numColumns            = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int a                     = ;
			int b                     = ;
			int numRows               = ;
			int numColumns            = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells(a, b, numRows, numColumns, k);
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
