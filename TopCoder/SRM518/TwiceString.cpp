// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//
You are given a string s.  Return the shortest string which contains s as a contiguous substring twice.

Note that two occurrences of s may overlap. For example, "ababa" contains "aba" twice.


DEFINITION
Class:TwiceString
Method:getShortest
Parameters:string
Returns:string
Method signature:string getShortest(string s)


NOTES
-The shortest string which contains s as a contiguous substring twice is always unique.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"aba"

Returns: "ababa"

This is the example shown in the problem statement.

1)
"xxxxx"

Returns: "xxxxxx"



2)
"topcoder"

Returns: "topcodertopcoder"



3)
"abracadabra"

Returns: "abracadabracadabra"



*/
// END CUT HERE
#line 60 "TwiceString.cpp"

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

class TwiceString {
public:
    string getShortest(string s) {
        int n = s.size();
        int equals = 0;
        for (int i = 0; i < n-1; i++) {
            string v = s.substr(0, i+1);
            if (v == s.substr(n - v.size())) {
                equals = v.size();
            }
        }
        return s + s.substr(equals);
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
			string s                  = "aba";
			string expected__         = "ababa";

			clock_t start__           = clock();
			string received__         = TwiceString().getShortest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "xxxxx";
			string expected__         = "xxxxxx";

			clock_t start__           = clock();
			string received__         = TwiceString().getShortest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "topcoder";
			string expected__         = "topcodertopcoder";

			clock_t start__           = clock();
			string received__         = TwiceString().getShortest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "abracadabra";
			string expected__         = "abracadabracadabra";

			clock_t start__           = clock();
			string received__         = TwiceString().getShortest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
          string s                  = "djuqjdj";
          string expected__         = "djuqjdjuqjdj";

          clock_t start__           = clock();
          string received__         = TwiceString().getShortest(s);
          return verify_case(casenum__, expected__, received__, clock()-start__);
      }
/*      case 5: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwiceString().getShortest(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwiceString().getShortest(s);
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
