// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Everybody who has lived in a village knows how expensive the things from the city are. And everybody who has lived in the city knows how expensive the things from the village are. Elly decided to use these observations to make some profit. She will start at some city or village, buy cheap stuff there, go to a place of the opposite type (village if she started in a city, or city if she started in a village) and sell it at a profit there, buying new stuff for the next place (again of the opposite type) and so on. Shortly after she leaves a city or village, the inhabitants realize how she tricked them and get angry at her, so she cannot go to the same place twice.
Elly cannot predict the actual profits she will make while using this strategy. Therefore she decided that she simply wants to visit as many places as possible. Of course, she has to alternate between visiting a village and visiting a city, and she may not visit the same place twice.

You are given a string places that describes all places Elly can visit. The i-th character of places is 'V' if the i-th place is a village, or 'C' if it is a city. Return the maximal number of places she can visit according to the rules above.

DEFINITION
Class:EllysTSP
Method:getMax
Parameters:string
Returns:int
Method signature:int getMax(string places)


NOTES
-Elly can travel directly between any two places.
-The minimal answer is 1 as she can start by visiting any one of the available places.
-The answer will never exceed the length of places, since she is not allowed to visit the same place more than once.


CONSTRAINTS
-places will contain between 1 and 50 characters, inclusive.
-Each character of places will be either 'V' or 'C'.


EXAMPLES

0)
"CVVVC"

Returns: 5

It is possible to visit all 5 places.
One solution is to start at place 1 (a village), go to place 0 (a city), then to place 2 (a village), place 4 (a city), and finally to place 3 (a village).

1)
"VVV"

Returns: 1

She may start by visiting any of the three villages. As there are no cities, she cannot make any more travels.

2)
"VVVVCVV"

Returns: 3

There is only one city among the places. Elly can go to any of the villages, then go to the city, and then to one of the other villages. Thus, the optimal result is 3.

3)
"CVCVCVC"

Returns: 7

Just visit the locations in the order in which they are given.

4)
"V"

Returns: 1

With only one place there is not much choice what to do.

*/
// END CUT HERE
#line 69 "EllysTSP.cpp"

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

#define D(x) cerr << #x << " = " << x << endl;
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
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  REP(i,0,z.size())os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; FOREACH(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class EllysTSP {
public:
    int getMax(string places) {
        int cities, village, n;
        cities = village = 0;
        n = places.length();

        REP(i, 0, n) {
            if(places[i] == 'C') cities++;
            else village++;
        }

        if(village < cities) {
            if(village == 0) return 1;
            if(village + 1 > cities) return cities + village;
            return village + village + 1;
        }

        if(cities < village) {
            if(cities == 0) return 1;
            if(cities + 1 > village) return cities + village;
            return cities + cities + 1;
        }

        return cities + village;
    }
};

// BEGIN CUT HERE
#include <cstdio>
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
			string places             = "CVVVC";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string places             = "VVV";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string places             = "VVVVCVV";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string places             = "CVCVCVC";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string places             = "V";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string places             = "VCVC";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string places             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string places             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysTSP().getMax(places);
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
