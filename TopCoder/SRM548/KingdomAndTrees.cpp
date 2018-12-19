// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// King Dengklek once planted N trees, conveniently numbered 0 through N-1, along the main highway in the Kingdom of Ducks. As time passed, the trees grew beautifully. Now, the height of the i-th tree is heights[i] units.

King Dengklek now thinks that the highway would be even more beautiful if the tree heights were in strictly ascending order. More specifically, in the desired configuration the height of tree i must be strictly smaller than the height of tree i+1, for all possible i. To accomplish this, King Dengklek will cast his magic spell. If he casts magic spell of level X, he can increase or decrease the height of each tree by at most X units. He cannot decrease the height of a tree into below 1 unit. Also, the new height of each tree in units must again be an integer.

Of course, a magic spell of a high level consumes a lot of energy. Return the smallest possible non-negative integer X such that King Dengklek can achieve his goal by casting his magic spell of level X.

DEFINITION
Class:KingdomAndTrees
Method:minLevel
Parameters:vector <int>
Returns:int
Method signature:int minLevel(vector <int> heights)


CONSTRAINTS
-heights will contain between 2 and 50 elements, inclusive.
-Each elements of heights will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{9, 5, 11}

Returns: 3

One possible solution that uses magic spell of level 3:

Decrease the height of the first tree by 2 units.
Increase the height of the second tree by 3 units.

The resulting heights are {7, 8, 11}.

1)
{5, 8}

Returns: 0

These heights are already sorted in strictly ascending order.

2)
{1, 1, 1, 1, 1}

Returns: 4

Since King Dengklek cannot decrease the heights of the trees below 1, the only possible solution is to cast his magic spell of level 4 to transform these heights into {1, 2, 3, 4, 5}.

3)
{548, 47, 58, 250, 2012}

Returns: 251



*/
// END CUT HERE
#line 61 "KingdomAndTrees.cpp"

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

bool can(int X, vector<int> h) {
    int n = h.size();

    int curr = max(1, h[0] - X);

    REP(i, 1, n) {
        if(curr + 1 > h[i] + X) return false;

        if(curr < h[i] - X) curr = h[i] - X;
        else curr++;
    }

    return true;
}

int solve(vector<int> heights) {
    int lo = 0, hi = INF;

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if(can(mid, heights)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

class KingdomAndTrees {
public:
    int minLevel(vector <int> heights) {
        return solve(heights);
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
			int heights[]             = {9, 5, 11};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int heights[]             = {5, 8};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int heights[]             = {1, 1, 1, 1, 1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int heights[]             = {548, 47, 58, 250, 2012};
			int expected__            = 251;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
          int heights[]             = {2,2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
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
