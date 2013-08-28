// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// On a horizontal line, there are N uniformly spaced vertical pillars.
The pillars are numbered 0 through N-1, in order.
For each i, the distance between the bottoms of pillars i and i+1 is exactly w.
For each i, the height of pillar i (0-based index) is an integer between 1 and heights[i], inclusive.
We want to take a single piece of rope and use it to join the top ends of all pillars, in order.
(Once in place, the rope will have the shape of a polyline consisting of N-1 segments.)
What is the shortest length of rope that is guaranteed to be sufficient, regardless of the actual pillar heights?

You are given the vector <int> heights and the int w.
Compute and return the answer to the above question.
In other words, find a sequence of pillar heights (within the given constraints) for which the length of the rope we need is maximized, and return that maximum.

DEFINITION
Class:PillarsDivTwo
Method:maximalLength
Parameters:vector <int>, int
Returns:double
Method signature:double maximalLength(vector <int> height, int w)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive.
-Each element of heights will be between 1 and 100, inclusive.
-w will be between 1 and 100, inclusive.


EXAMPLES

0)
{3,3,3}
2

Returns: 5.656854249492381



1)
{1,1,1,1}
100

Returns: 300.0



2)
{100,2,100,2,100}
4

Returns: 396.32310051270036

We will need the most rope if columns 0, 2, and 4 have height 100 each, and columns 1 and 3 have height 1 each.

3)
{2,1,1,2}
1

Returns: 3.82842712474619



*/
// END CUT HERE
#line 71 "PillarsDivTwo.cpp"

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

double pillars[111][51];

double dist(int b, int h) {
    return hypot((double)b, (double)h);
}

double solve(vector<int> height, int w) {
    int n = height.size();
    memset(pillars, 0, sizeof(pillars));

    REP(i, 1, n) {
        REP(j, 1, height[i]+1) {
            double d = -INF;
            REP(k , 1, height[i-1]+1) {
                d = max(d, pillars[k][i-1] + dist(w, j - k));
            }
            pillars[j][i] = d;
        }
    }

    double best = 0.0;
    REP(i, 1, height[n-1]+1) best = max(best, pillars[i][n-1]);

    return best;
}

class PillarsDivTwo {
public:
    double maximalLength(vector <int> height, int w) {
        return solve(height, w);
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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int height[]              = {3,3,3};
			int w                     = 2;
			double expected__         = 5.656854249492381;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int height[]              = {1,1,1,1};
			int w                     = 100;
			double expected__         = 300.0;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int height[]              = {100,2,100,2,100};
			int w                     = 4;
			double expected__         = 396.32310051270036;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int height[]              = {2,1,1,2};
			int w                     = 1;
			double expected__         = 3.82842712474619;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int height[]              = ;
			int w                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int height[]              = ;
			int w                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int height[]              = ;
			int w                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PillarsDivTwo().maximalLength(vector <int>(height, height + (sizeof height / sizeof height[0])), w);
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
