// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Ciel lives in a beautiful countryside.
She loves climbing mountains.
Yesterday, she went hiking in the mountains.



Her trip can be described as a sequence of (n+1) integers: h[0], h[1], ..., h[n]. 
These values represent altitudes visited by Fox Ciel during the trip, in order.
Fox Ciel does not remember the precise sequence, but she remembers the following:

for each i, h[i] >= 0
h[0] = 0
h[n] = 0
for each i, abs(h[i+1]-h[i]) = 1




The last condition means that in each step the altitude of Fox Ciel either increased by 1, or decreased by 1.
We will call the two types of steps "steps up" and "steps down", respectively.
Steps up will be denoted 'U' and steps down will be denoted 'D'.



You are given the int n: the length of the trip.
In addition to the length, Fox Ciel remembers some contiguous segment of her trip.
You are given this segment as a string history.
Each character of history is either 'U' or 'D'.



Let X be the number of different trips that match everything that Fox Ciel remembers.
(Note that she may be mistaken, hence X may also be zero.)
Compute and return the value (X modulo 1,000,000,009).

DEFINITION
Class:FoxAndMountain
Method:count
Parameters:int, string
Returns:int
Method signature:int count(int n, string history)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-history will contain between 1 and n characters, inclusive.
-Each character in history will be either 'U' or 'D'.


EXAMPLES

0)
4
"UUDD"

Returns: 1

Fox Ciel remembers the entire history of her trip. The corresponding sequence of altitudes is {0, 1, 2, 1 ,0}.

1)
4
"DUUD"

Returns: 0

Fox Ciel is mistaken. 
As n=4 and history="DUUD", the corresponding sequence of altitudes has to be {0, -1, 0, 1, 0}.
However, all altitudes must be non-negative, so there is no matching trip.

2)
4
"UU"

Returns: 1

The complete history must be "UUDD".

3)
49
"U"

Returns: 0

It is not hard to see that for an odd n the answer has to be 0.

4)
20
"UUUDUUU"

Returns: 990



5)
30
"DUDUDUDUDUDUDUDU"

Returns: 3718



6)
50
"U"

Returns: 946357703

Don't forget to use the modulo operations during the calculation.

*/
// END CUT HERE
#line 116 "FoxAndMountain.cpp"

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

class FoxAndMountain {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int count(int n, string history) {
        
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
			int n                     = 4;
			string history            = "UUDD";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 4;
			string history            = "DUUD";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 4;
			string history            = "UU";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 49;
			string history            = "U";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 20;
			string history            = "UUUDUUU";
			int expected__            = 990;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 30;
			string history            = "DUDUDUDUDUDUDUDU";
			int expected__            = 3718;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int n                     = 50;
			string history            = "U";
			int expected__            = 946357703;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			string history            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			string history            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			string history            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndMountain().count(n, history);
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
