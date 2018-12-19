// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//
For strings x and y, we say y is a subsequence of x if y can be obtained from x by erasing some (possibly all or none) of the letters in x. For example, "tpcdr" is a subsequence of "topcoder", while "rt" is not.

Given a string s, return the lexicographically largest subsequence of s.


DEFINITION
Class:LargestSubsequence
Method:getLargest
Parameters:string
Returns:string
Method signature:string getLargest(string s)


NOTES
-For strings x and y, x is said to be lexicographically larger than y if y is a prefix of x or y has a smaller character than x at the first position where they differ. Order of characters is defined as the order of ASCII codes: 'a' < 'b' < ... < 'z'.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"test"

Returns: "tt"

All subsequences listed in lexicographical order are "" (empty string), "e", "es", "est", "et", "s", "st", "t", "te", "tes", "test", "tet", "ts", "tst" and "tt". So return "tt".

1)
"a"

Returns: "a"

There are only two subsequences, "" and "a".

2)
"example"

Returns: "xple"



3)
"aquickbrownfoxjumpsoverthelazydog"

Returns: "zyog"



*/
// END CUT HERE
#line 60 "LargestSubsequence.cpp"

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

int find(string s) {
    int max = s.size() - 1;
    for (int i = s.size() - 2; i >= 0; i--)
        if (s[i] > s[max]) max = i;
    return max;
}

string remove(string s, char x, int start) {
    string ret;
    for (int i = start; i >= 0; i--) {
        if (s[i] == x) ret += s[i];
    }
    return ret;
}

string solve(string s) {
    if(s.size() == 0) return "";

    int x = find(s);
    string ret = remove(s, s[x], x) + solve(s.substr(x + 1));
    return ret;
}


class LargestSubsequence {
public:
    string getLargest(string s) {
        return solve(s);
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
			string s                  = "test";
			string expected__         = "tt";

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "a";
			string expected__         = "a";

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "example";
			string expected__         = "xple";

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "aquickbrownfoxjumpsoverthelazydog";
			string expected__         = "zyog";

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LargestSubsequence().getLargest(s);
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
