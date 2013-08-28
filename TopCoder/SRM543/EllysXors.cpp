// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// XOR problems became very popular in TopCoder recently. (If you do not know the bitwise operation XOR, see the Notes section for an explanation.) That's why Elly decided to invent one of her own. Fortunately for you, the one she came up with is quite simple. You are given two long longs L and R. She wants you to find the XOR of all numbers between L and R, inclusive.

DEFINITION
Class:EllysXors
Method:getXor
Parameters:long long, long long
Returns:long long
Method signature:long long getXor(long long L, long long R)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-One of the ways to calculate the XOR of more than two numbers A1, A2, ..., An is "A1 XOR (A2 XOR (... XOR An))..))". Since the function is commutative and associative, you can also express it as "A1 XOR A2 XOR ... XOR An" and group the operands in any way you like.
-It can be proved that the answer is always less than 2*R for the given constraints.


CONSTRAINTS
-L and R will be between 1 and 4,000,000,000, inclusive.
-L will be less than or equal to R.


EXAMPLES

0)
3
10

Returns: 8


((((((3 XOR 4) XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 =
        (((((7 XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 =
                ((((2 XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 =
                        (((4 XOR 7) XOR 8) XOR 9) XOR 10 =
                                ((3 XOR 8) XOR 9) XOR 10 =
                                       (11 XOR 9) XOR 10 =
                                                2 XOR 10 = 8.


1)
5
5

Returns: 5

The XOR of a single number is the number itself.

2)
13
42

Returns: 39

A bit larger example.

3)
666
1337

Returns: 0

The answer can be zero.

4)
1234567
89101112

Returns: 89998783



*/
// END CUT HERE
#line 79 "EllysXors.cpp"

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

class EllysXors {
public:
    long long xor1n(long long n) {
        int mod = n % 4;
        if(mod == 0) return n;
        if(mod == 1) return 1;
        if(mod == 2) return n+1;
        return 0;
    }

    long long getXor(long long L, long long R) {
        return xor1n(R) ^ xor1n(L-1);
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

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
			long long L               = 3;
			long long R               = 10;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long L               = 5;
			long long R               = 5;
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long L               = 13;
			long long R               = 42;
			long long expected__      = 39;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long L               = 666;
			long long R               = 1337;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long L               = 1234567;
			long long R               = 89101112;
			long long expected__      = 89998783;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

        case 5: {
			long long L               = 1;
			long long R               = 4000000000;
			long long expected__      = 4000000000;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			long long L               = ;
			long long R               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long L               = ;
			long long R               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysXors().getXor(L, R);
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
