// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are a wizard.
You are facing N fairies, numbered 0 through N-1.
Your goal is to defeat all of them.
You can only attack one fairy at a time.
Moreover, you must fight the fairies in order: you can only attack fairy X+1 after you defeat fairy X.
On the other hand, all fairies that have not been defeated yet will attack you all the time.



Each fairy has two characteristics: her damage per second (dps) and her amount of hit points.
Your damage per second is 1.
That is, you are able to reduce an opponent's hit points by 1 each second.
In other words, if a fairy has H hit points, it takes you H seconds to defeat her.



You are given two vector <int>s, each of length N: dps and hp.
For each i, dps[i] is the damage per second of fairy i, and hp[i] is her initial amount of hit points.
We assume that your number of hit points is sufficiently large to avoid defeat when fighting the fairies.
Compute and return the total number of hit points you'll lose during the fight.
In other words, return the total amount of damage the attacking fairies will deal.

DEFINITION
Class:GreatFairyWar
Method:minHP
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minHP(vector <int> dps, vector <int> hp)


NOTES
-Damage per second (dps) of a person P is the rate at which P can deal damage to their opponents.


CONSTRAINTS
-dps will contain between 1 and 30 elements, inclusive.
-dps and hp will contain the same number of elements.
-Each element in dps will be between 1 and 30, inclusive.
-Each element in hp will be between 1 and 30, inclusive.


EXAMPLES

0)
{1,2}
{3,4}

Returns: 17

It will take you 3 seconds to defeat fairy 0 and then 4 seconds to defeat fairy 1.
During the first 3 seconds both fairies attack you, dealing 1+2 = 3 damage each second.
During the next 4 seconds fairy 1 continues to attack you, dealing 2 damage each second.
The total number of hit points you lose is 3*(1+2) + 4*2 = 9 + 8 = 17.

1)
{1,1,1,1,1,1,1,1,1,1}
{1,1,1,1,1,1,1,1,1,1}

Returns: 55

The answer is 10+9+...+3+2+1 = 55.

2)
{20,12,10,10,23,10}
{5,7,7,5,7,7}

Returns: 1767



3)
{5,7,7,5,7,7}
{20,12,10,10,23,10}

Returns: 1998



4)
{30,2,7,4,7,8,21,14,19,12}
{2,27,18,19,14,8,25,13,21,30}

Returns: 11029



5)
{1}
{1}

Returns: 1



*/
// END CUT HERE
#line 101 "GreatFairyWar.cpp"

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

class GreatFairyWar {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int minHP(vector <int> dps, vector <int> hp) {
        int n = (int)dps.size();
        int sum_dps = 0;
        REP(i, 0, n) sum_dps += dps[i];
        int damage = 0;

        REP(i, 0, n) {
            damage += hp[i] * sum_dps;
            sum_dps -= dps[i];
        }

        return damage;
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
			int dps[]                 = {1,2};
			int hp[]                  = {3,4};
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int dps[]                 = {1,1,1,1,1,1,1,1,1,1};
			int hp[]                  = {1,1,1,1,1,1,1,1,1,1};
			int expected__            = 55;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int dps[]                 = {20,12,10,10,23,10};
			int hp[]                  = {5,7,7,5,7,7};
			int expected__            = 1767;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int dps[]                 = {5,7,7,5,7,7};
			int hp[]                  = {20,12,10,10,23,10};
			int expected__            = 1998;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int dps[]                 = {30,2,7,4,7,8,21,14,19,12};
			int hp[]                  = {2,27,18,19,14,8,25,13,21,30};
			int expected__            = 11029;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int dps[]                 = {1};
			int hp[]                  = {1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int dps[]                 = ;
			int hp[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int dps[]                 = ;
			int hp[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int dps[]                 = ;
			int hp[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GreatFairyWar().minHP(vector <int>(dps, dps + (sizeof dps / sizeof dps[0])), vector <int>(hp, hp + (sizeof hp / sizeof hp[0])));
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
