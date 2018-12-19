// BEGIN CUT HERE
/*
PROBLEM STATEMENT
We are in a distant future.
After the downfall of mankind, the Earth is now ruled by fairies.
The "Turing game Online" website is hot among fairies right now.
On this website, everyone can play the programming puzzle "Turing game".

Fairies love powers of 5, that is, the numbers 1, 5, 25, 125, 625, and so on.
In the Turing game, the player is given a string of bits (zeros and ones).
The ideal situation is when the string is represents a power of 5 in binary, with no leading zeros.
If that is not the case, the fairy player tries to cut the given string into pieces, each piece being a binary representation of a power of 5, with no leading zeros.
Of course, it may be the case that even this is impossible.
In that case, the fairy player becomes depressed, and bad things happen when a fairy gets depressed.
You, as one of the surviving humans, are in charge of checking the bit strings to prevent the bad things from happening.

You are given a string S that consists of characters '0' and '1' only.
S represents the string given to a player of the Turing game.
Return the smallest positive integer K such that it is possible to cut S into K pieces, each of them being a power of 5.
If there is no such K, return -1 instead.

DEFINITION
Class:CuttingBitString
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be either '0' or '1'.


EXAMPLES

0)
"101101101"

Returns: 3

We can split the given string into three "101"s.
Note that "101" is 5 in binary.

1)
"1111101"

Returns: 1

"1111101" is 5^3.

2)
"00000"

Returns: -1

0 is not a power of 5.

3)
"110011011"

Returns: 3

Split it into "11001", "101" and "1".

4)
"1000101011"

Returns: -1



5)
"111011100110101100101110111"

Returns: 5



*/
// END CUT HERE
#line 83 "CuttingBitString.cpp"

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
typedef unsigned long long uint64;
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

vector<uint64> powers;

uint64 convert(string s) {
    uint64 r = 0;

    int n = s.size();

    for(int i = n-1, j = 0; i >= 0; i--, j++) {
        if(s[i] == '1')
            r |= (1LL << j);
    }

    return r;
}

bool is_power(string s) {
    uint64 r = convert(s);

    REP(i, 0, 22) {
        if(r == powers[i])
            return true;
    }

    return false;
}

class CuttingBitString {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int getmin_aux(string S) {
        if(S == "") return 0;
        if(S[0] == '0') return INF;

        if(is_power(S)) return 1;

        int ans = INF;

        int n = S.size();

        for(int i = 1; i < n; i++) {
            if(S[i] == '1' && S[i-1] == '1') {
                if(is_power(S.substr(0, i))) {
                    int c = getmin(S.substr(i));
                    if(c > 0)
                        ans = min(ans, 1 + c);
                }
            }
        }

        if(ans == INF) ans = -1;
        return ans;
    }

    int getmin(string S) {
        powers.clear();

        unsigned long long x = 1;
        REP(i, 0, 22) {
            powers.push_back(x);
            x *= 5;
        }

        int ans = getmin_aux(S);

        if(ans == INF) return -1;
        return ans;
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
			string S                  = "101101101";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "1111101";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "00000";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "110011011";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "1000101011";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "111011100110101100101110111";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			string S                  = "1010";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
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
