// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <int> S containing a set of pairwise distinct positive integers.

Return the size of the largest subset T of S such that any two numbers from T are relatively prime.

DEFINITION
Class:RelativelyPrimeSubset
Method:findSize
Parameters:vector <int>
Returns:int
Method signature:int findSize(vector <int> S)


NOTES
-Two integers A and B are relatively prime if and only if their greatest common divisor equals to 1.


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element of S will be between 1 and 100, inclusive.
-All elements in S will be distinct.


EXAMPLES

0)
{2,3,7,11,4}

Returns: 4

One such subset T is {2,3,7,11}, another is {3,4,7,11}.

1)
{4,8,12,16}

Returns: 1



2)
{100,17,81,82}

Returns: 3



3)
{2,3,4,5,6}

Returns: 3



*/
// END CUT HERE
#line 59 "RelativelyPrimeSubset.cpp"

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

int solve(vector<int> S) {
    int n = S.size();
    vector< vector<int> > ans(n);

    REP(i, 0, n) {
        ans[i].push_back(S[i]);
        REP(j, 0, n) if(S[i] != S[j]) {
            bool ok = true;
            REP(k, 0, ans[i].size()) {
                if(__gcd(ans[i][k], S[j]) != 1) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans[i].push_back(S[j]);
        }
    }
    D(ans);
    REP(i, 0, S.size()) {
        D(i); D(ans[i].size());
    }
    int best = -1;
    REP(i, 0, n) best = max(best, (int)ans[i].size());
    return best;
}

class RelativelyPrimeSubset {
public:
    int findSize(vector <int> S) {
        return solve(S);
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
			int S[]                   = {2,3,7,11,4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {4,8,12,16};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {100,17,81,82};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {2,3,4,5,6};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

        case 4: {
			int S[]                   = {34, 1, 13, 70, 35, 25, 23, 92, 79, 68, 12, 96, 46, 63, 48, 24, 39, 58, 72, 5, 100, 91, 60, 17, 74, 3, 22, 83, 93, 37, 27, 38, 6, 82, 36, 69, 30, 89, 45, 59, 43, 54, 4, 62, 95, 7, 28, 65, 42, 19};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
        case 5: {
			int S[]                   = {3, 4, 8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int S[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RelativelyPrimeSubset().findSize(vector <int>(S, S + (sizeof S / sizeof S[0])));
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
