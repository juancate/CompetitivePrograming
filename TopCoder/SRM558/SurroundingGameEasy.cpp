// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Surrounding Game is a single-player game played on a rectangular grid of cells.
Cells are considered adjacent if they share a common side.
(Hence, each cell has at most four adjacent cells.
The cells on the sides and in the corners of the grid have fewer adjacent cells than the ones inside the grid.)

The game is played by placing stones into some of the cells.
Each cell may only contain at most one stone.
A cell is called dominated if at least one of the following two conditions holds:

The cell contains a stone.
All cells adjacent to the cell contain stones.


Each cell of the grid contains two numbers, each from 0 to 9, inclusive:
the cost of placing a stone into the cell, and the benefit from dominating the cell.
At the end of the game, the overall score of the player is the sum of all benefits minus the sum of all costs.

You are given the vector <string>s cost and benefit.
The characters cost[i][j] and benefit[i][j] represent the two digits written in the cell (i,j).
For example, if character 7 of element 4 of cost is '3', the cost of placing a stone into the cell (4,7) is 3.

You are also given a vector <string> stone that describes the final state of the game.
The character stone[i][j] is 'o' (lowercase letter oh) if the cell (i,j) contains a stone.
Otherwise, stone[i][j] is '.' (a period).
Calculate and return the overall score of the game.

DEFINITION
Class:SurroundingGameEasy
Method:score
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int score(vector <string> cost, vector <string> benefit, vector <string> stone)


CONSTRAINTS
-cost will contain between 2 and 20 elements, inclusive.
-cost, benefit and stone will each contain the same number of elements.
-Each element of cost will contain between 2 and 20 characters, inclusive.
-Each element of cost will contain the same number of characters.
-Each element of benefit and stone will contain the same number of characters as each element of cost.
-Each character in cost and benefit will be a digit ('0'-'9').
-Each character in stone will either 'o' (lowercase letter oh) or '.'.


EXAMPLES

0)
{"21","12"}
{"21","12"}
{".o","o."}

Returns: 4

All the cells are dominated, so the overall benefit is 2+1+1+2 = 6.
Only two of the cells contain stones.
The total cost of placing the stones is 1+1 = 2.
Therefore the overall score is 6-2 = 4.

1)
{"99","99"}
{"11","11"}
{".o","o."}

Returns: -14

A player may get a negative score.

2)
{"888","888","888"}
{"000","090","000"}
{"...",".o.","..."}

Returns: 1



3)
{"4362","4321"}
{"5329","5489"}
{"...o","..o."}

Returns: 22



4)
{"5413","4323","8321","5490"}
{"0432","7291","3901","2310"}
{"ooo.","o..o","...o","oooo"}

Returns: -12



*/
// END CUT HERE
#line 101 "SurroundingGameEasy.cpp"

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

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool valid(int nr, int nc, int n, int m) {
    return nr >= 0 && nr < n && nc >= 0 && nc < m;
}

class SurroundingGameEasy {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int score(vector <string> cost, vector <string> benefit, vector <string> stone) {
        int n = (int)stone.size();
        int m = (int)stone[0].size();

        int b = 0, c = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(stone[i][j] == 'o') {
                    b += benefit[i][j] - '0';
                    c += cost[i][j] - '0';
                } else {
                    bool dominated = true;
                    for(int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(valid(nr, nc, n, m)) {
                            dominated &= stone[nr][nc] == 'o';
                        }
                    }

                    if(dominated) b += benefit[i][j] - '0';
                }
            }
        }
        return b - c;
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
			string cost[]             = {"21","12"};
			string benefit[]          = {"21","12"};
			string stone[]            = {".o","o."};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cost[]             = {"99","99"};
			string benefit[]          = {"11","11"};
			string stone[]            = {".o","o."};
			int expected__            = -14;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cost[]             = {"888","888","888"};
			string benefit[]          = {"000","090","000"};
			string stone[]            = {"...",".o.","..."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cost[]             = {"4362","4321"};
			string benefit[]          = {"5329","5489"};
			string stone[]            = {"...o","..o."};
			int expected__            = 22;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cost[]             = {"5413","4323","8321","5490"};
			string benefit[]          = {"0432","7291","3901","2310"};
			string stone[]            = {"ooo.","o..o","...o","oooo"};
			int expected__            = -12;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          string cost[]             = {"11"};
          string benefit[]          = {"11"};
          string stone[]            = {"oo"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string cost[]             = ;
			string benefit[]          = ;
			string stone[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cost[]             = ;
			string benefit[]          = ;
			string stone[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SurroundingGameEasy().score(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector <string>(stone, stone + (sizeof stone / sizeof stone[0])));
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
