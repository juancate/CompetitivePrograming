// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A Ball Triangle is a set of identical balls placed in a triangular shape. A Ball Triangle has N rows, numbered 1 to N from top to bottom. For all i, 1 <= i <= N, the i-th row contains i balls. For example, the following image shows a Ball Triangle with N=3.




Fox Jiro has infinitely many Ball Triangles. He can paint a Ball Triangle according to the following conditions:

Each of the balls has to be painted either red, green, or blue.
No two adjacent balls may share the same color.

The following image shows one valid coloring of a Ball Triangle for N=3.




Jiro wants to paint as many Ball Triangles as he can.
As long as he follows the rules above, he may color the Ball Triangles in any way he likes.
Some of the colored Ball Triangles may look exactly the same, but they don't have to.
The only other constraint is the total amount of paint available to Jiro:
In all the triangles together, he can paint at most R balls red, G balls green, and B balls blue.

You are given the long longs R, G, and B.
You are also given the int N.
Return the maximum possible number of Ball Triangles Jiro can paint.

DEFINITION
Class:FoxPaintingBalls
Method:theMax
Parameters:long long, long long, long long, int
Returns:long long
Method signature:long long theMax(long long R, long long G, long long B, int N)


CONSTRAINTS
-R, G and B will each be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
2
2
3

Returns: 1

Jiro can paint one Ball Triangle in the same way as in the image in the statement.

1)
1
2
3
3

Returns: 0

This time Jiro can paint no Ball Triangles.

2)
8
6
6
4

Returns: 2



3)
7
6
7
4

Returns: 2



4)
100
100
100
4

Returns: 30



5)
19330428391852493
48815737582834113
11451481019198930
3456

Returns: 5750952686



6)
1
1
1
1

Returns: 3



*/
// END CUT HERE
#line 117 "FoxPaintingBalls.cpp"

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

bool can(int64 R, int64 G, int64 B, int64 c, int64 balls, int64 res) {
    int64 rr = R - balls * c;
    int64 gg = G - balls * c;
    int64 bb = B - balls * c;

    if(rr < 0 || gg < 0 || bb < 0)
        return false;

    return (rr + gg + bb) >= (res * c);
}

class FoxPaintingBalls {
public:
    long long theMax(long long R, long long G, long long B, int N) {
        int64 balls = N * (N + 1LL) / 2;

        int64 total = balls / 3;
        int64 total_r = balls % 3;

        int64 lo = 0, hi = (R+G+B) / balls + 1LL;

        while(lo < hi) {
            int64 mid = lo + (hi - lo) / 2;

            if(!can(R, G, B, mid, total, total_r))
                hi = mid;
            else
                lo = mid+1;
        }
        return lo-1;
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
			long long R               = 2;
			long long G               = 2;
			long long B               = 2;
			int N                     = 3;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long R               = 1;
			long long G               = 2;
			long long B               = 3;
			int N                     = 3;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long R               = 8;
			long long G               = 6;
			long long B               = 6;
			int N                     = 4;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long R               = 7;
			long long G               = 6;
			long long B               = 7;
			int N                     = 4;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long R               = 100;
			long long G               = 100;
			long long B               = 100;
			int N                     = 4;
			long long expected__      = 30;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long R               = 19330428391852493LL;
			long long G               = 48815737582834113LL;
			long long B               = 11451481019198930LL;
			int N                     = 3456;
			long long expected__      = 5750952686LL;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			long long R               = 1;
			long long G               = 1;
			long long B               = 1;
			int N                     = 1;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			long long R               = ;
			long long G               = ;
			long long B               = ;
			int N                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long R               = ;
			long long G               = ;
			long long B               = ;
			int N                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			long long R               = ;
			long long G               = ;
			long long B               = ;
			int N                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxPaintingBalls().theMax(R, G, B, N);
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
