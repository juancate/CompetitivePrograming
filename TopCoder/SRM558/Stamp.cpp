// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Little Fox Jiro has a rectangular board.
On the board there is a row of N unit cells.
The cells are numbered 0 through N-1 from the left to the right.
Initially, the cells are not colored.
Jiro must color each of the cells red, green, or blue.

You are given a string desiredColor with N characters.
For each i, character i of desiredColor represents the color Jiro must use for cell i.
If a character is one of 'R' (as red), 'G' (as green), and 'B' (as blue), it means that Jiro must use that particular color.
If a character is '*', Jiro may use any of the three colors for the particular cell.

You are also given the ints stampCost and pushCost that describe the cost of the coloring process.
The coloring process consists of two phases.
In the first phase, Jiro must pick a single stamp he will then use to color all the cells.
The length L of the stamp can be any integer between 1 and N, inclusive.
A stamp of length L costs L*stampCost.

In the second phase, Jiro must repeatedly use the stamp to color the cells.
Each use of the stamp works as follows:

Jiro picks one of the three colors and pushes the stamp into ink of the chosen color C.
Jiro picks a segment of L contiguous cells such that each of them is either uncolored or already has the color C.
The segment must be completely inside the board.
That is, the leftmost cell of the segment must be one of the cells 0 through N-L.
Jiro pushes the stamp onto the chosen segment of cells. All the cells now have color C.

Each use of the stamp costs pushCost.

Return the smallest possible total cost of coloring all the cells using the above process.


DEFINITION
Class:Stamp
Method:getMinimumCost
Parameters:string, int, int
Returns:int
Method signature:int getMinimumCost(string desiredColor, int stampCost, int pushCost)


CONSTRAINTS
-desiredColor will contain between 1 and 50 characters, inclusive.
-Each character of desiredColor will be either 'R' or 'G' or 'B' or '*'.
-stampCost will be between 1 and 100,000, inclusive.
-pushCost will be between 1 and 100,000, inclusive.


EXAMPLES

0)
"RRGGBB"
1
1

Returns: 5

The optimal solution is to choose L=2 and then stamp three times: using red color for cells [0,1], green for [2,3], and blue for [4,5].
The stamp costs 2*1 = 2, each of the three uses costs 1, so the total costs is 2*1 + 3*1 = 5.

1)
"R**GB*"
1
1

Returns: 5

The optimal solution is the same as in the previous example.
Note that you must color all the cells, so choosing L=1 and then using the stamp three times is not a valid solution.

2)
"BRRB"
2
7

Returns: 30

Also, note that once a cell is colored, you are not allowed to stamp over it using a different color.
Therefore, you can only choose L=1 in this case.

3)
"R*RR*GG"
10
58

Returns: 204

It is allowed to stamp the same cell multiple times if all of those stamps use the same color.

4)
"*B**B**B*BB*G*BBB**B**B*"
5
2

Returns: 33



5)
"*R*RG*G*GR*RGG*G*GGR***RR*GG"
7
1

Returns: 30



*/
// END CUT HERE
#line 112 "Stamp.cpp"

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

class Stamp {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
        
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
			string desiredColor       = "RRGGBB";
			int stampCost             = 1;
			int pushCost              = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string desiredColor       = "R**GB*";
			int stampCost             = 1;
			int pushCost              = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string desiredColor       = "BRRB";
			int stampCost             = 2;
			int pushCost              = 7;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string desiredColor       = "R*RR*GG";
			int stampCost             = 10;
			int pushCost              = 58;
			int expected__            = 204;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string desiredColor       = "*B**B**B*BB*G*BBB**B**B*";
			int stampCost             = 5;
			int pushCost              = 2;
			int expected__            = 33;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string desiredColor       = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
			int stampCost             = 7;
			int pushCost              = 1;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
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
