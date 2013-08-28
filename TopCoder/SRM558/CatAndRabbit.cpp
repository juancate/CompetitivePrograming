// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Cat and Rabbit are going to play the following game. 


There are some tiles in a row. 
Each of the tiles is colored white or black. 
You are given a string tiles, describing the initial arrangement of tiles. 
The characters '.' and '#' represent a white tile and a black tile, respectively. 


Cat and Rabbit take alternating turns. Cat plays first. 
In each turn, the following actions must be performed: 

	First, the player must select a black tile and step on it. 
	Then, the player must make some steps (as many as they want, but at least one). 
		In each step, the player must select an adjacent white tile, move to that tile, and change its color to black. 

The animal who is unable to take a valid turn loses the game. 
Return the string "Cat" if Cat will win, "Rabbit" if Rabbit will win, assuming both animals play optimally. 


DEFINITION
Class:CatAndRabbit
Method:getWinner
Parameters:string
Returns:string
Method signature:string getWinner(string tiles)


CONSTRAINTS
-tiles will contain between 1 and 50 characters, inclusive. 
-Each character in tiles will be '.' or '#'. 


EXAMPLES

0)
"#.."

Returns: "Cat"

In the first turn, Cat will select the leftmost tile and can move to the right twice. 
Then Rabbit has no legal move and loses. 


1)
".#."

Returns: "Rabbit"

In the first turn, Cat must select the middle tile. 
Then, Cat can decide whether to step to the left or to the right.
In the second turn, Rabbit will select the middle tile and then step in the opposite direction. 


2)
"###"

Returns: "Rabbit"

Cat has no legal move at the beginning of the game. 


3)
"#..##.#"

Returns: "Cat"

4)
"..."

Returns: "Rabbit"



5)
"###...####....###...####...."

Returns: "Rabbit"



*/
// END CUT HERE
#line 88 "CatAndRabbit.cpp"

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

class CatAndRabbit {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    string getWinner(string tiles) {
        
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
			string tiles              = "#..";
			string expected__         = "Cat";

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string tiles              = ".#.";
			string expected__         = "Rabbit";

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string tiles              = "###";
			string expected__         = "Rabbit";

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string tiles              = "#..##.#";
			string expected__         = "Cat";

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string tiles              = "...";
			string expected__         = "Rabbit";

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string tiles              = "###...####....###...####....";
			string expected__         = "Rabbit";

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string tiles              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string tiles              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string tiles              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CatAndRabbit().getWinner(tiles);
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
