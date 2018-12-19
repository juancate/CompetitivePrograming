// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Beaver Bindu has some chocolates arranged in a row.
The wrapping of each chocolate has a single color.
Multiple chocolates can share the same color.
In this problem, each of the possible colors is represented by an uppercase letter.
You are given a string chocolates.
For each i, the i-th chocolate (0-based index) in the row has the color chocolates[i].


The spread of a row of chocolates is the maximum number of adjacent chocolates that all share the same color.
Formally, the spread can be defined as the maximum value of (j-i+1), where i <= j and all the chocolates in the positions between i and j, inclusive, have the same color.


You are also given an int maxSwaps.
Bindu can swap any two adjacent chocolates.
She has decided to make at most maxSwaps such swaps.


Return the maximum spread she can obtain.


DEFINITION
Class:ColorfulChocolates
Method:maximumSpread
Parameters:string, int
Returns:int
Method signature:int maximumSpread(string chocolates, int maxSwaps)


CONSTRAINTS
-chocolates will contain between 1 and 50 characters, inclusive.
-Each character in chocolates will be an uppercase letter ('A'-'Z').
-maxSwaps will be between 1 and 2500, inclusive.


EXAMPLES

0)
"ABCDCBC"
1

Returns: 2

One optimal solution is to swap chocolates at positions 2 and 3, obtaining the row "ABDCCBC", which has spread 2.


1)
"ABCDCBC"
2

Returns: 3

The only optimal solution is to produce the row "ABDCCCB".


2)
"ABBABABBA"
3

Returns: 4

The row "ABBBBAABA" can be produced with 3 swaps.

3)
"ABBABABBA"
4

Returns: 5

An optimal solution is to produce the row "AABBBBBAA".

4)
"QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"
77

Returns: 5

*/
// END CUT HERE
#line 83 "ColorfulChocolates.cpp"

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

int solve(string chocolates, int swaps) {
    int ans = -INF;
    int n = (int)chocolates.size();

    D(chocolates); D(swaps);

    for(char c = 'A'; c <= 'Z'; c++) {
        vector<int> cnt;

        for(int i = 0; i < n; i++)
            if(c == chocolates[i])
                cnt.push_back(i);

        for(int i = 0; i < (int)cnt.size(); i++) {
            int d = 0;
            int current = 1;
            int last = cnt[i];
            D(c);
            for(int j = i+1; j < (int)cnt.size(); j++) {
                int pos = cnt[j] - last - 1;
                d += pos;

                if(chocolates[pos + last] != c)
                    last += pos;
                else
                    last = cnt[j];
                if(pos == 0) last++;

                if(d <= swaps) {
                    current++;
                    ans = max(ans, current);
                } else {
                    break;
                }
            }
            ans = max(ans, current);
        }
    }
    return ans;
}

class ColorfulChocolates {
public:
    int maximumSpread(string chocolates, int maxSwaps) {
        return solve(chocolates, maxSwaps);
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
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string chocolates         = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
			int maxSwaps              = 77;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
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
