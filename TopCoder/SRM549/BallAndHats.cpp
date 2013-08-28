// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A magician has invited you to play a game. For this game, the magician uses a special table. On the table there are three spots in a row. The spots are labeled 0, 1, and 2, in order. He places three hats onto the table, so that each hat covers one of the spots. He then takes a ball and places it under one of the hats. The hats are not transparent, so you cannot see the ball while it is under a hat. Next, the magician shuffles the hats by repeatedly swapping two adjacent hats. Each swap is done by sliding the hats along the table, never showing you the ball.
Once the magician finishes swapping the hats, you have to guess the spot where the ball is.

You are given a string hats which describes the contents of the hats in the beginning of the game. The i-th character of hats is 'o' if the ball was initially on the spot i. Otherwise, the i-th character of hats is '.' (a period).

You are also given a int numSwaps. Assume that the magician swapped the hat that contained the ball exactly numSwaps times. Please remember that in our version of the game the magician always swaps two adjacent hats. Also, note that the total number of swaps in the game may be larger than numSwaps, because the magician may sometimes swap two hats that don't contain the ball.

Assume that the magician chose the swaps he makes uniformly at random. That is, in each turn with probability 50% he swapped the hats on spots 0 and 1, and with probability 50% he swapped the hats on spots 1 and 2. Return the number of the spot that is most likely to contain the ball at the end of the game. If multiple spots are tied for the largest probability, return the smallest one of them.

DEFINITION
Class:BallAndHats
Method:getHat
Parameters:string, int
Returns:int
Method signature:int getHat(string hats, int numSwaps)


NOTES
-Two hats are adjacent if their spots differ by 1.


CONSTRAINTS
-hats will contain exactly three characters.
-hats will contain exactly one 'o' character.
-hats will contain exactly two '.' characters.
-numSwaps will be between 0 and 1000, inclusive.


EXAMPLES

0)
".o."
1

Returns: 0

The spots 0 and 2 are equally likely to contain the ball after the hat that contains it is swapped once.
We return the smallest spot number, which is 0.

1)
"..o"
0

Returns: 2

The ball does not change spots when 0 swaps are performed; therefore, the ball must be at spot 2.

2)
"o.."
1

Returns: 1



3)
"..o"
2

Returns: 0



4)
"o.."
101

Returns: 1



*/
// END CUT HERE
#line 78 "BallAndHats.cpp"

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

class BallAndHats {
public:
    int getHat(string hats, int numSwaps) {
        int pos = (hats[0] == 'o')? 0 : (hats[1] == 'o')? 1 : 2;

        if(numSwaps == 0) return pos;

        if(pos == 0) {
            if(numSwaps & 1) return 1;
            return 0;
        }
        if(pos == 1) {
            if(numSwaps & 1) return 0;
            return 1;
        }
        if(pos == 2) {
            if(numSwaps & 1) return 1;
            return 0;
        }
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
			string hats               = ".o.";
			int numSwaps              = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string hats               = "..o";
			int numSwaps              = 0;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string hats               = "o..";
			int numSwaps              = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string hats               = "..o";
			int numSwaps              = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string hats               = "o..";
			int numSwaps              = 101;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string hats               = ;
			int numSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string hats               = ;
			int numSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string hats               = ;
			int numSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallAndHats().getHat(hats, numSwaps);
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
