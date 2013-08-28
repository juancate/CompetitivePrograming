// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In the Land of Winter lives the Toy King. The Toy King owns many fields and in each field he has control over different plots of land. The Toy King also has nine lords under him. To each of his lords he has given control over some of the plots in his kingdom. Now he wishes to use some of those plots to make train tracks for a winter celebration.

To build his train tracks the king can use three types of track pieces. Each of these pieces resembles a puzzle piece where each end can be positive or negative.




A type A piece of track rotates by 90 degrees and has two positive ends.
A type B piece of track rotates by 90 degrees and has two negative ends.
A straight piece has both one positive and one negative end.


Notice how the positive end fits snugly together with the negative end. The ends of two pieces of track can connect if and only if one end is positive and one end is negative. This makes creating connected tracks very easy. Simply place two pieces of track side by side and make sure the positive and negative ends interlock.

Currently, some plots of land are empty and others contain pieces of track of various types. Each plot of land can contain at most one piece of track. While forming the new tracks, the king allowed you to rotate the existing pieces of track in increments of 90 degrees. Additionally, you are allowed to add new straight pieces onto empty plots of land. Each of these new pieces can have any of the four possible orientations. You are not allowed to add new pieces of types A and B.

You are given a vector <string> field that describes a rectangular area of the country, divided into unit square plots of land.

Each character of each element of field describes one plot of land. The meanings of individual characters follow.

The character '.' represents an empty plot of land.
The character 'A' represents a plot occupied by a type A piece.
The character 'B' represents a plot occupied by a type B piece.
The character 'S' represents a plot of land occupied by a straight piece.
If the character is a digit 'x' (where 'x' is from '1' to '9'), it represents a plot of land owned by the lord number x.


The king would like to have a non-empty set of closed track segments. More precisely, in the final configuration there must be at least one track piece and each track piece has to be connected to two other track pieces. Note that in the final configuration there may be more than one closed sequence of tracks. Sometimes it may happen that it is impossible to build the tracks without using plots that were assigned to some of the lords. If the king wishes to use one or more plots that were assigned to lord i, he will pay the lord exactly i gold coins. Paying the i coins once allows the king to use all the plots that were assigned to lord i. Adding new straight pieces does not cost anything. The king would like to know the minimum total amount of gold coins he would have to pay to make the train tracks. Return this minimum amount. If it is not possible to build the train tracks, return -1 instead.

DEFINITION
Class:ToyTrain
Method:getMinCost
Parameters:vector <string>
Returns:int
Method signature:int getMinCost(vector <string> field)


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each element of field will contain between 1 and 50 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character of each element of field will be 'A', 'B', 'S', '.' or a digit between '1' and '9', inclusive.


EXAMPLES

0)
{"BA",
 "SS",
 "AB"}

Returns: 0



1)
{"."}

Returns: -1

It is not possible to build any closed train tracks.

2)
{"ABBA",
 "BAAB"}

Returns: 0

The King can make two separate tracks for this field.

3)
{"AA",
 "AA"}


Returns: -1



4)
{"..AB",
 "B..A",
 "....",
 "A.B."}

Returns: -1



5)
{"A1B8A2B",
 "16A.B22",
 "BAB.9.A",
 "ABA.7.B",
 "B12345A"}

Returns: 31



6)
{"..A.B",
 ".1.2.",
 "A.B..",
 ".3.4.",
 "B...A"}

Returns: 0



7)
{"ASBSBSA",
 "S.S.S.S",
 "BSASASB"}

Returns: -1



*/
// END CUT HERE
#line 127 "ToyTrain.cpp"

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

class ToyTrain {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int getMinCost(vector <string> field) {
        
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
			string field[]            = {"BA",
 "SS",
 "AB"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {"."};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"ABBA",
 "BAAB"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"AA",
 "AA"}
;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string field[]            = {"..AB",
 "B..A",
 "....",
 "A.B."};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string field[]            = {"A1B8A2B",
 "16A.B22",
 "BAB.9.A",
 "ABA.7.B",
 "B12345A"};
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string field[]            = {"..A.B",
 ".1.2.",
 "A.B..",
 ".3.4.",
 "B...A"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string field[]            = {"ASBSBSA",
 "S.S.S.S",
 "BSASASB"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToyTrain().getMinCost(vector <string>(field, field + (sizeof field / sizeof field[0])));
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
