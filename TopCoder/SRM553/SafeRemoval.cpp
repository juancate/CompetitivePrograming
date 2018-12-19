// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Did you know that platypuses can be very superstitious? A certain platypus was on a mission to remove exactly k numbers from a sequence in such a way that the sum of the remaining numbers is as large as possible. This task would have been very simple, were it not the case that our platypus wants to avoid some unlucky situations.

More precisely, our platypus thinks that the number 4 is unlucky, and so are all its multiples.
Fortunately, the sum of the original sequence of numbers is not a multiple of 4. The platypus wants to keep it that way. It will only consider removing a number from the sequence if after the removal the sum of the remaining elements is not a multiple of 4. We will call such a removal safe.

You are given vector <int> seq and int k. If it is possible to perform exactly k safe removals (one element at a time), return the maximum possible sum of the elements remaining after the k removals. In case it is not possible to perform k safe removals, return -1.

DEFINITION
Class:SafeRemoval
Method:removeThem
Parameters:vector <int>, int
Returns:int
Method signature:int removeThem(vector <int> seq, int k)


CONSTRAINTS
-seq will contain between 2 and 50 elements, inclusive.
-Each element of seq will be between 1 and 1000, inclusive.
-k will be at least 1. 
-k will be less than the number of elements in seq.
-The sum of all elements of seq will not be a multiple of 4.


EXAMPLES

0)
{3, 8, 4}
1

Returns: 11

The best move for the platypus is to remove 4.
The platypus cannot remove 3, because the remaining elements would add up to 4+8 = 12, a multiple of 4.
Removing 8 is safe, but the total sum of the remaining elements, 3+4=7 is smaller than 11.

1)
{1,1,1,1,1,1}
3

Returns: -1

The initial sum is 6. After removing any of the elements, the sum becomes 5. At that point it becomes impossible to remove any of the remaining elements without making the sum a multiple of 4.

2)
{1,6,1,10,1,2,7,11}
6

Returns: 21



3)
{1,1,1,1,1,1,1,1,7}
3

Returns: 6

One of the three removed elements has to be the 7. The platypus has to remove the elements either in the order 1,7,1, or in the order 1,1,7.

*/
// END CUT HERE
#line 66 "SafeRemoval.cpp"

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

class SafeRemoval {
public:
    int removeThem(vector <int> seq, int k) {
        
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
			int seq[]                 = {3, 8, 4};
			int k                     = 1;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {1,1,1,1,1,1};
			int k                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {1,6,1,10,1,2,7,11};
			int k                     = 6;
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {1,1,1,1,1,1,1,1,7};
			int k                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
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
