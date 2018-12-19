// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Your friend the farmer liked to use the following method to count the number of beavers and ducks present on the farm: He would first find three ints webbedFeet, duckBills and beaverTails, representing  the number of webbed feet, duck bills and beaver tails he could count and then he used those numbers to find the number of ducks and beavers on the farm. (A duck has one duck bill and two webbed feet. A beaver has one beaver tail and four webbed feet.)

The method worked great until he received news that there could be a platypus invasion on the farm. A platypus is a marvellous creature that has 4 webbed feet, a duck bill and a beaver tail. Our farmer is justifiably confused. Help him find out that his method is still useful. You are given ints webbedFeet, duckBills and beaverTails that specify the number of webbed feet, duck bills and beaver tails  the farmer has counted, respectively. Return the total number of animals (ducks, beavers, and platypuses) on the farm. The constraints guarantee that there will be exactly one solution.

DEFINITION
Class:PlatypusDuckAndBeaver
Method:minimumAnimals
Parameters:int, int, int
Returns:int
Method signature:int minimumAnimals(int webbedFeet, int duckBills, int beaverTails)


CONSTRAINTS
-webbedFeet, duckBills and beaverTails will each be between 0 and 1000, inclusive.
-There will be exactly one way to assign the number of ducks, beavers and platypuses such that the total number of each specific kind of body part matches webbedFeet, duckBills and beaverTails, respectively.


EXAMPLES

0)
4
1
1

Returns: 1

If there is only one platypus, it will have 4 webbed feet, 1 beaver tail and 1 duck bill. Matching the description.

1)
0
0
0

Returns: 0



2)
10
2
2

Returns: 3

One platypus, one duck and one beaver.

3)
60
10
10

Returns: 20

10 ducks and 10 beavers.

4)
1000
200
200

Returns: 300



*/
// END CUT HERE
#line 71 "PlatypusDuckAndBeaver.cpp"

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


class PlatypusDuckAndBeaver {
public:
    int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
        int best = -1, d, b;

        for(int i = 0; i <= 1000; i++) {
            for(int j = 0; j <= 1000; j++) {
                int ducks = duckBills - i;
                int beavers = beaverTails - j;

                if(ducks < 0 || beavers < 0)
                    break;

                int feet = webbedFeet - 2 * i - 4 * j;
                if(feet < 0) break;

                if(ducks == beavers && feet % 4 == 0) {
                    int p = feet / 4;

                    if(ducks - p > 0 || beavers - p > 0)
                        break;

                    int total = (i + j + p);
                    if(total > best) {
                        d = i, b = j;
                        best = total;
                    }
                }
            }
        }

        return best;
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
			int webbedFeet            = 4;
			int duckBills             = 1;
			int beaverTails           = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int webbedFeet            = 0;
			int duckBills             = 0;
			int beaverTails           = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int webbedFeet            = 10;
			int duckBills             = 2;
			int beaverTails           = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int webbedFeet            = 60;
			int duckBills             = 10;
			int beaverTails           = 10;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int webbedFeet            = 1000;
			int duckBills             = 200;
			int beaverTails           = 200;
			int expected__            = 300;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int webbedFeet            = 1000;
			int duckBills             = 1000;
			int beaverTails           = 1000;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int webbedFeet            = ;
			int duckBills             = ;
			int beaverTails           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int webbedFeet            = ;
			int duckBills             = ;
			int beaverTails           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
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
