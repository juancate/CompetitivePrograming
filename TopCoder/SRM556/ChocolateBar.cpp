// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You just bought a very delicious chocolate bar from a local store. This chocolate bar consists of N squares, numbered 0 through N-1. All the squares are arranged in a single row. There is a letter carved on each square. You are given a string letters. The i-th character of letters denotes the letter carved on the i-th square (both indices are 0-based).

You want to share this delicious chocolate bar with your best friend. At first, you want to give him the whole bar, but then you remembered that your friend only likes a chocolate bar without repeated letters. Therefore, you want to remove zero or more squares from the beginning of the bar, and then zero or more squares from the end of the bar, in such way that the remaining bar will contain no repeated letters.

Return the maximum possible length of the remaining chocolate bar that contains no repeated letters.

DEFINITION
Class:ChocolateBar
Method:maxLength
Parameters:string
Returns:int
Method signature:int maxLength(string letters)


CONSTRAINTS
-letters will contain between 1 and 50 characters, inclusive.
-Each character of letters will be a lowercase letter ('a' - 'z').


EXAMPLES

0)
"srm"

Returns: 3

You can give the whole chocolate bar as it contains no repeated letters.

1)
"dengklek"

Returns: 6

Remove two squares from the end of the bar.

2)
"haha"

Returns: 2

There are three possible ways:

Remove two squares from the beginning of the bar.
Remove two squares from the end of the bar.
Remove one square from the beginning of the bar and one square from the end of the bar.


3)
"www"

Returns: 1



4)
"thisisansrmbeforetopcoderopenfinals"

Returns: 9



*/
// END CUT HERE
#line 68 "ChocolateBar.cpp"

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

class ChocolateBar {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int maxLength(string letters);
};

int ChocolateBar::maxLength(string letters) {
    int ans = 0;
    int n = letters.size();

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= 0; j--) {
            map<char, int> r;
            for(int k = i; k <= j; k++) {
                r[letters[k]]++;
            }

            bool ok = true;
            FOREACH(c, r) {
                if(c->second > 1) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                ans = max(ans, j-i+1);
            }
        }
    }

    return ans;
}

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
			string letters            = "srm";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string letters            = "dengklek";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string letters            = "haha";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string letters            = "www";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string letters            = "thisisansrmbeforetopcoderopenfinals";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string letters            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letters            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string letters            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChocolateBar().maxLength(letters);
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
