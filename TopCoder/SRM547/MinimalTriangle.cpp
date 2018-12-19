// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a int length.
We have a regular hexagon: a polygon with six sides, in which all internal angles have 120 degrees and length is the length of each side.
We are going to draw three non-intersecting diagonals in some way.
These will divide the hexagon into four triangles.
We will then compute their areas, take a piece of paper and write down the smallest of those four areas.
Compute and return the largest number we can obtain on our piece of paper (by choosing which diagonals to draw).

DEFINITION
Class:MinimalTriangle
Method:maximalArea
Parameters:int
Returns:double
Method signature:double maximalArea(int length)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-length will be between 1 and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
5

Returns: 10.825317547305485



1)
10

Returns: 43.30127018922194



2)
100000

Returns: 4.330127018922194E9



*/
// END CUT HERE
#line 53 "MinimalTriangle.cpp"

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

const double PI = acos(-1.0);

class MinimalTriangle {
public:
    double sqr(double x) { return x * x;}
    double maximalArea(int length) {
        double c = 2 * sqr(length) - 2 * sqr(length) * cos(120 * PI / 180.);
        double h = sqrt(sqr(length) - (c / 4.));
        return (sqrt(c) * h) / 2.;
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
			int length                = 5;
			double expected__         = 10.825317547305485;

			clock_t start__           = clock();
			double received__         = MinimalTriangle().maximalArea(length);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int length                = 10;
			double expected__         = 43.30127018922194;

			clock_t start__           = clock();
			double received__         = MinimalTriangle().maximalArea(length);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int length                = 100000;
			double expected__         = 4.330127018922194E9;

			clock_t start__           = clock();
			double received__         = MinimalTriangle().maximalArea(length);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int length                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MinimalTriangle().maximalArea(length);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int length                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MinimalTriangle().maximalArea(length);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int length                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MinimalTriangle().maximalArea(length);
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
