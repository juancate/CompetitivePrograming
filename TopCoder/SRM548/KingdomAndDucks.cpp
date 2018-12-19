// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// King Dengklek received a container full of ducks as his birthday gift from his loyal subjects. Each duck is of a specific type, represented by an integer between 1 and 50, inclusive. He was told that the container contains the same number of ducks of each type that is present in the container.

King Dengklek wants to guess the total number of ducks in the container. He removed some of the ducks from the container and examined their types. These types are given in vector <int> duckTypes, where duckTypes[i] is the type of the i-th duck (0-based index) King Dengklek picked.

Compute and return the total number of ducks in the container in the beginning (before King Dengklek removed some of them). If there are multiple possibilities, return the smallest one.

DEFINITION
Class:KingdomAndDucks
Method:minDucks
Parameters:vector <int>
Returns:int
Method signature:int minDucks(vector <int> duckTypes)


CONSTRAINTS
-duckTypes will contain between 1 and 50 elements, inclusive.
-Each element of duckTypes will be between 1 and 50, inclusive.


EXAMPLES

0)
{5, 8}

Returns: 2

The container might have contained one duck of each of types 5 and 8.

1)
{4, 7, 4, 7, 4}

Returns: 6

The container might have contained three ducks of each of types 4 and 7.

2)
{17, 17, 19, 23, 23, 19, 19, 17, 17}

Returns: 12



3)
{50}

Returns: 1

The container might have contained only one duck of type 50.

4)
{10, 10, 10, 10, 10}

Returns: 5



*/
// END CUT HERE
#line 63 "KingdomAndDucks.cpp"

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

class KingdomAndDucks {
public:
    int minDucks(vector <int> duckTypes) {
        vector<int> ducks(51, 0);
        int ans = -1, cnt = 0;
        int n = duckTypes.size();
        REP(i, 0, n) {
            if(ducks[ duckTypes[i] ] == 0) cnt++;
            ducks[duckTypes[i]]++;
            if(ducks[duckTypes[i]] > ans)
                ans = ducks[duckTypes[i]];
        }
        return ans * cnt;
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
			int duckTypes[]           = {5, 8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int duckTypes[]           = {4, 7, 4, 7, 4};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int duckTypes[]           = {17, 17, 19, 23, 23, 19, 19, 17, 17};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int duckTypes[]           = {50};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int duckTypes[]           = {10, 10, 10, 10, 10};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int duckTypes[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int duckTypes[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int duckTypes[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndDucks().minDucks(vector <int>(duckTypes, duckTypes + (sizeof duckTypes / sizeof duckTypes[0])));
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
