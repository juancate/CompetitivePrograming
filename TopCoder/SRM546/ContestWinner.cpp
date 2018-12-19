// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//
Exactly one million contestants, numbered 1 through 1,000,000, took part in a programming contest.
The rules of the contest are simple: the winner is the contestant who solves the largest number of tasks.
If there are more contestants tied for most tasks solved, the winner is the one who was the first to have all of their tasks solved.


During the contest the judges were keeping a log of all accepted solutions.
You are given this log as a vector <int> events.
The i-th element of events is the number of the contestant who submitted the i-th accepted solution (both indices are 0-based).


For example, if events = {4, 7, 4, 1}, this is what happened during the contest:


Contestant 4 solved her first task.
Contestant 7 solved his first task.
Contestant 4 solved her second task.
Contestant 1 solved his first task.


Compute and return the number of the contestant who won the contest.


DEFINITION
Class:ContestWinner
Method:getWinner
Parameters:vector <int>
Returns:int
Method signature:int getWinner(vector <int> events)


CONSTRAINTS
-events will contain between 1 and 50 elements, inclusive.
-Each element of events will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{4,7,4,1}

Returns: 4

Example from the problem statement.

1)
{10,20,30,40,50}

Returns: 10



2)
{123,123,456,456,456,123}

Returns: 456



3)
{1,2,2,3,3,3,4,4,4,4}

Returns: 4



*/
// END CUT HERE
#line 73 "ContestWinner.cpp"

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

int solve(vector<int> events) {
    vector<int> contestants(1000000, 0);
    int n = events.size();
    int winner = -1, count = 0;
    REP(i, 0, n) {
        contestants[events[i]]++;
        if(count < contestants[events[i]]) {
            winner = events[i];
            count = contestants[events[i]];
        }
    }
    return winner;
}

class ContestWinner {
public:
    int getWinner(vector <int> events) {
        return solve(events);
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
			int events[]              = {4,7,4,1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int events[]              = {10,20,30,40,50};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int events[]              = {123,123,456,456,456,123};
			int expected__            = 456;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int events[]              = {1,2,2,3,3,3,4,4,4,4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
          int events[]              = {1000000, 1, 1, 1000000, 1000000};
			int expected__            = 1000000;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int events[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int events[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
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
