// BEGIN CUT HERE
/*
PROBLEM STATEMENT

The old song declares "Go ahead and hate your neighbor", and the residents of
Onetinville have taken those words to heart.  Every resident hates his next-door
neighbors on both sides.  Nobody is willing to live farther away from the town's
well than his neighbors, so the town has been arranged in a big circle around
the well.  Unfortunately, the town's well is in disrepair and needs to be restored.  You
have been hired to collect donations for the Save Our Well fund.



Each of the town's residents is willing to donate a certain amount, as specified in the vector <int>
donations, which is listed in clockwise order around the well.  However, nobody is willing to
contribute to a fund to which his neighbor has also contributed.  Next-door neighbors are always listed
consecutively in donations, except that the first and last entries in donations are also
for next-door neighbors.  You must calculate and return the maximum amount of donations that can be collected.



DEFINITION
Class:BadNeighbors
Method:maxDonations
Parameters:vector <int>
Returns:int
Method signature:int maxDonations(vector <int> donations)


CONSTRAINTS
-donations contains between 2 and 40 elements, inclusive.
-Each element in donations is between 1 and 1000, inclusive.


EXAMPLES

0)
 { 10, 3, 2, 5, 7, 8 }

Returns: 19

The maximum donation is 19, achieved by 10+2+7.  It would be better to take 10+5+8 except that
the 10 and 8 donations are from neighbors.

1)
{ 11, 15 }

Returns: 15

2)
{ 7, 7, 7, 7, 7, 7, 7 }

Returns: 21

3)
{ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }

Returns: 16

4)
{ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }

Returns: 2926

*/
// END CUT HERE
#line 70 "BadNeighbors.cpp"

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

int n;
int dp[50];
vector<int> donations;

int solve() {
    dp[0] = donations[0];
    int last = 0;
    for(int i = 2; i < n; i += 2)  {
        if(i == n-1) continue;
        dp[i] += donations[i] + dp[i-2];
        last = i;
    }
    for(int i = 0; i < n; i += 2)
        cerr << dp[i] << ' ';
    cerr << endl;
    dp[1] = donations[1];
    int last_2 = 1;
    for(int i = 3; i < n; i += 2) {
        dp[i] += donations[i] + dp[i-2];
        last_2 = i;
    }
    for(int i = 1; i < n; i += 2)
        cerr << dp[i] << ' ';
    cerr << endl;
    return max(dp[last], dp[last_2]);
}

class BadNeighbors {
public:
    int maxDonations(vector <int> d) {
        donations = d;
        n = d.size();
        memset(dp, 0, sizeof(dp));
        return solve();
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
			int donations[]           =  { 10, 3, 2, 5, 7, 8 };
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int donations[]           = { 11, 15 };
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int donations[]           = { 7, 7, 7, 7, 7, 7, 7 };
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int donations[]           = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int donations[]           = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
			int expected__            = 2926;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int donations[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int donations[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int donations[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BadNeighbors().maxDonations(vector <int>(donations, donations + (sizeof donations / sizeof donations[0])));
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
