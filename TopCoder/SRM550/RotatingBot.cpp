// BEGIN CUT HERE
/*
PROBLEM STATEMENT
NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

We had a rectangular grid that consisted of W x H square cells.
We placed a robot on one of the cells.
The robot then followed the rules given below.


Initially, the robot is facing east.
The robot moves in steps. In each step it moves to the adjacent cell in the direction it currently faces.
The robot may not leave the grid.
The robot may not visit the same cell twice. (This also means that it may not reenter the starting cell.)
If a step forward does not cause the robot to break the above rules, the robot takes the step.
Otherwise, the robot rotates 90 degrees to the left (counter-clockwise) and checks whether a step forward still breaks the above rules.
  If not, the robot takes the step and continues executing this program (still rotated in the new direction).
If the rotation left did not help, the robot terminates the execution of this program.
We can also terminate the execution of the program manually, at any moment.

For example, the following seven images show a series of moves made by the robot in a 12 x 11 board:


We forgot the dimensions of the grid and the original (x,y) coordinates of the cell on which the robot was originally placed, but we do remember its movement. You are given a vector <int> moves. This sequence of positive integers shall be interpreted as follows:
The robot performed moves[0] steps eastwards, turned left, performed moves[1] steps northwards, turned left, and so on.
After performing the last sequence of steps, the robot stopped. (Either it detected that it should terminate, or we stopped it manually.) We are not sure if the sequence of moves is valid. If the sequence of moves is impossible, return -1. Else, return the minimum area of a grid in which the sequence of moves is possible.
(I.e., the return value is the smallest possible value of the product of W and H.).

DEFINITION
Class:RotatingBot
Method:minArea
Parameters:vector <int>
Returns:int
Method signature:int minArea(vector <int> moves)


CONSTRAINTS
-moves will contain between 1 and 50 elements, inclusive.
-Each element of moves will be between 1 and 50, inclusive.


EXAMPLES

0)
{15}

Returns: 16

The smallest valid board is a 16x1 board, with the robot starting on the west end of the board.

1)
{3,10}

Returns: 44

The smallest solution is to place the robot into the southwest corner of a 4 x 11 board.

2)
{1,1,1,1}

Returns: -1

This sequence of moves is not possible because the robot would return to its initial location which is forbidden.

3)
{9,5,11,10,11,4,10}

Returns: 132

These moves match the image from the problem statement.

4)
{12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}

Returns: 420

5)
{8,6,6,1}

Returns: -1



6)
{8,6,6}

Returns: 63



7)
{5,4,5,3,3}

Returns: 30



*/
// END CUT HERE
#line 101 "RotatingBot.cpp"

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

typedef pair<int,int> ii;
#define mp make_pair

class RotatingBot {
public:
    int minArea(vector <int> moves) {
        set<ii> visited;

        int n = moves.size();
        int start_x = 0, start_y = 0, dir = 0;
        visited.insert( mp(start_x, start_y) );

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < moves[i]; j++) {
                if(dir == 0) start_x++;
                if(dir == 1) start_y++;
                if(dir == 2) start_x--;
                if(dir == 3) start_y--;

                if(visited.count( mp(start_x, start_y) ))
                    return -1;

                visited.insert( mp(start_x, start_y) );
            }
            dir = (dir + 1) % 4;
        }

        int min_x = INF, max_x = -INF, min_y = INF, max_y = -INF;

        FOREACH(p, visited) {
            min_x = min(min_x, p->first);
            max_x = max(max_x, p->first);
            min_y = min(min_y, p->second);
            max_y = max(max_y, p->second);
        }

        visited.clear();
        start_x = 0, start_y = 0, dir = 0;
        visited.insert( mp(start_x, start_y) );

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < moves[i]; j++) {
                if(dir == 0) start_x++;
                if(dir == 1) start_y++;
                if(dir == 2) start_x--;
                if(dir == 3) start_y--;

                visited.insert( mp(start_x, start_y) );
            }

            if(dir == 0) {
                if(start_x < max_x && !visited.count( mp(start_x+1, start_y) ) && i != n-1)
                    return -1;
            }
            if(dir == 1) {
                if(start_y < max_y && !visited.count( mp(start_x, start_y+1) ) && i != n-1)
                    return -1;
            }
            if(dir == 2) {
                if(min_x < start_x && !visited.count( mp(start_x-1, start_y) ) && i != n-1)
                    return -1;
            }
            if(dir == 3) {
                if(min_y < start_y && !visited.count( mp(start_x, start_y-1) ) && i != n-1)
                    return -1;
            }

            dir = (dir + 1) % 4;
        }

        int W = max_x - min_x + 1;
        int H = max_y - min_y + 1;

        return W * H;
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
			int moves[]               = {15};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int moves[]               = {3,10};
			int expected__            = 44;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int moves[]               = {1,1,1,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int moves[]               = {9,5,11,10,11,4,10};
			int expected__            = 132;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int moves[]               = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
			int expected__            = 420;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int moves[]               = {8,6,6,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int moves[]               = {8,6,6};
			int expected__            = 63;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int moves[]               = {5,4,5,3,3};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 8: {
          int moves[]               = {1,1,2,2,4};
          int expected__            = -1;

          clock_t start__           = clock();
          int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
          return verify_case(casenum__, expected__, received__, clock()-start__);
      }
      case 9: {
          int moves[]               = {1,2,3,4,5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
      }
      case 10: {
          int moves[]               = {4,3,5,4,6,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
      }
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
