// BEGIN CUT HERE
/*
PROBLEM STATEMENT
We have a string originalWord. Each character of originalWord is either 'a' or 'b'. Timmy claims that he can convert it to finalWord using exactly k moves. In each move, he can either change a single 'a' to a 'b', or change a single 'b' to an 'a'.

You are given the strings originalWord and finalWord, and the int k. Determine whether Timmy may be telling the truth.
If there is a possible sequence of exactly k moves that will turn originalWord into finalWord, return "POSSIBLE" (quotes for clarity).
Otherwise, return "IMPOSSIBLE".

DEFINITION
Class:EasyConversionMachine
Method:isItPossible
Parameters:string, string, int
Returns:string
Method signature:string isItPossible(string originalWord, string finalWord, int k)


NOTES
-Timmy may change the same letter multiple times. Each time counts as a different move.


CONSTRAINTS
-originalWord will contain between 1 and 50 characters, inclusive.
-finalWord and originalWord will contain the same number of characters.
-Each character in originalWord and finalWord will be 'a' or 'b'.
-k will be between 1 and 100, inclusive.


EXAMPLES

0)
"aababba"
"bbbbbbb"
2

Returns: "IMPOSSIBLE"

It is not possible to reach finalWord in fewer than 4 moves.

1)
"aabb"
"aabb"
1

Returns: "IMPOSSIBLE"

The number of moves must be exactly k=1.

2)
"aaaaabaa"
"bbbbbabb"
8

Returns: "POSSIBLE"

Use each move to change each of the letters once.

3)
"aaa"
"bab"
4

Returns: "POSSIBLE"

The following sequence of 4 moves does the job:
aaa -> baa -> bab -> aab -> bab

4)
"aababbabaa"
"abbbbaabab"
9

Returns: "IMPOSSIBLE"



*/
// END CUT HERE
#line 80 "EasyConversionMachine.cpp"

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

class EasyConversionMachine {
public:
    string isItPossible(string originalWord, string finalWord, int k) {
        int n = originalWord.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(originalWord[i] != finalWord[i]) cnt++;
        }
        if(cnt > k) return "IMPOSSIBLE";
        return (cnt == k || (k - cnt) % 2 == 0)? "POSSIBLE" : "IMPOSSIBLE";
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

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string originalWord       = "aababba";
			string finalWord          = "bbbbbbb";
			int k                     = 2;
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string originalWord       = "aabb";
			string finalWord          = "aabb";
			int k                     = 1;
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string originalWord       = "aaaaabaa";
			string finalWord          = "bbbbbabb";
			int k                     = 8;
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string originalWord       = "aaa";
			string finalWord          = "bab";
			int k                     = 4;
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string originalWord       = "aababbabaa";
			string finalWord          = "abbbbaabab";
			int k                     = 9;
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

        case 5: {
          string originalWord       = "aaa";
          string finalWord          = "bbb";
          int k                     = 100;
          string expected__         = "IMPOSSIBLE";

          clock_t start__           = clock();
          string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
          return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
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
