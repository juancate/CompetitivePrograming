// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The Order of the Hats is a magical organization. One of their duties is to teach students how to cast spells. There are N spells numbered from 0 to N-1. As an aid for the students, the teachers have prepared a spell chart. The chart lists suggestions on the order in which to study the spells. (This is explained in more detail below.)



Recently, some changelings broke into the Order's spell archive and messed up the spell chart. You are given a vector <string> spellChart containing the new, messed-up state of the spell chart. Each character of each element of spellChart is either 'Y' or 'N'. The students will come to study soon. They will interpret the chart in the following way: If spellChart[i][j] is 'Y' then spell i must be learned before spell j. 

As the chart is now messed up, it may be impossible to learn all the spells in the chart because of cycles in the requirements. Your task is to repair the given chart. Determine the minimum number of changes needed to remove all the cycles in the requirements. In a single change, you may either change some character spellChart[i][j] from 'Y' to 'N', or change some character from 'N' to 'Y'. 

DEFINITION
Class:OrderOfTheHats
Method:minChanged
Parameters:vector <string>
Returns:int
Method signature:int minChanged(vector <string> spellChart)


CONSTRAINTS
-spellChart will contain between 1 and 20 elements, inclusive.
-Each element of spellChart will contain N characters, where N is the number of elements in spellChart.
-Each character in each element of spellChart will be either 'Y' or 'N'.


EXAMPLES

0)
{"Y"}

Returns: 1

This spell chart contains a spell that should be learned before itself. The students would never be able to learn such a spell.
We can remove this cyclic dependency by changing the 'Y' to 'N'.

1)
{"NYN",
 "NNY",
 "NNN"}


Returns: 0

This spell chart is already OK.

2)
{"NYN",
 "NNY",
 "YNN"}

Returns: 1

Changing any single 'Y' to a 'N' will fix this spell chart.

3)
{"NYYYYYY",
 "YNYYYYY",
 "YYNYYYY",
 "YYYNYYY",
 "YYYYNYY",
 "YYYYYNY",
 "YYYYYYN"}

Returns: 21



4)
{"NNNY",
 "YNYN",
 "YNNN",
 "YYYN"}

Returns: 1



5)
{"YYYYYNNYYYNYNNNNYNNY",
 "NYNNNYYNNYNYYYNYYYYY",
 "NNYNNNYYNNNNNNYYYYNY",
 "YYNYNYYNNYYYNYNNNYYY",
 "NYYNNYNYNYNNNNYYYNYN",
 "NNNNNYYNYNNYYYYNYYYN",
 "YNYNYYNNNYNNNNNYNNYY",
 "NYYYYNYNYNNYNNYNNNNY",
 "YYYYNYYNNYYYNNYNNYNY",
 "YYYYYYNYNYNYNNNNNNYN",
 "NNYYYYYNNNYNNNYNNNNY",
 "YYNNNYNYYNYYNYYNYNYN",
 "NNYNYYNYYNYYNYNYNYYN",
 "YNYNYYNYNNNYNYNYYNYY",
 "NNYNNNYYYYYYYYYYYNYY",
 "YYYYYNYYNYYYYYNNYNNN",
 "NYYYYYYYYNNNNNYYNNYN",
 "YNNYNNNYYNYYYNYNYYYY",
 "YYNNYNYYYNYYNNNYYNNY",
 "NNYNYNYYYNYYNYNNYNNN"}

Returns: 79



6)
{"YYNYNN",
 "YNYNNY",
 "YYYYNN",
 "NNNYNN",
 "NNNYNN",
 "YNYNYN"}

Returns: 5



7)
{"NNNNNNNNNN",
 "NNNNNNNNNN",
 "NNNYNNYNNN",
 "NNNYNNYNNN",
 "NNNYNNYNNN",
 "NNNNNNNNNN",
 "NNYYYYYYNN",
 "NNYNNNNYNN",
 "NNNYYYYNNN",
 "NNNNNNNNNN"}

Returns: 6



*/
// END CUT HERE
#line 135 "OrderOfTheHats.cpp"

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

class OrderOfTheHats {
public:
    int minChanged(vector <string> spellChart) {
        
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
			string spellChart[]       = {"Y"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string spellChart[]       = {"NYN",
 "NNY",
 "NNN"}
;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string spellChart[]       = {"NYN",
 "NNY",
 "YNN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string spellChart[]       = {"NYYYYYY",
 "YNYYYYY",
 "YYNYYYY",
 "YYYNYYY",
 "YYYYNYY",
 "YYYYYNY",
 "YYYYYYN"};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string spellChart[]       = {"NNNY",
 "YNYN",
 "YNNN",
 "YYYN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string spellChart[]       = {"YYYYYNNYYYNYNNNNYNNY",
 "NYNNNYYNNYNYYYNYYYYY",
 "NNYNNNYYNNNNNNYYYYNY",
 "YYNYNYYNNYYYNYNNNYYY",
 "NYYNNYNYNYNNNNYYYNYN",
 "NNNNNYYNYNNYYYYNYYYN",
 "YNYNYYNNNYNNNNNYNNYY",
 "NYYYYNYNYNNYNNYNNNNY",
 "YYYYNYYNNYYYNNYNNYNY",
 "YYYYYYNYNYNYNNNNNNYN",
 "NNYYYYYNNNYNNNYNNNNY",
 "YYNNNYNYYNYYNYYNYNYN",
 "NNYNYYNYYNYYNYNYNYYN",
 "YNYNYYNYNNNYNYNYYNYY",
 "NNYNNNYYYYYYYYYYYNYY",
 "YYYYYNYYNYYYYYNNYNNN",
 "NYYYYYYYYNNNNNYYNNYN",
 "YNNYNNNYYNYYYNYNYYYY",
 "YYNNYNYYYNYYNNNYYNNY",
 "NNYNYNYYYNYYNYNNYNNN"};
			int expected__            = 79;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string spellChart[]       = {"YYNYNN",
 "YNYNNY",
 "YYYYNN",
 "NNNYNN",
 "NNNYNN",
 "YNYNYN"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string spellChart[]       = {"NNNNNNNNNN",
 "NNNNNNNNNN",
 "NNNYNNYNNN",
 "NNNYNNYNNN",
 "NNNYNNYNNN",
 "NNNNNNNNNN",
 "NNYYYYYYNN",
 "NNYNNNNYNN",
 "NNNYYYYNNN",
 "NNNNNNNNNN"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string spellChart[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string spellChart[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string spellChart[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = OrderOfTheHats().minChanged(vector <string>(spellChart, spellChart + (sizeof spellChart / sizeof spellChart[0])));
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
