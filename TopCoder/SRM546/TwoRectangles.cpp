// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//
You are given two rectangles in the plane.
The sides of each rectangle are parallel to the coordinate axes.
Each rectangle is given by the coordinates of its lower left corner and its upper right corner.
You are given two vector <int>s: A and B.
A describes the first rectangle: its lower left corner has coordinates (A[0],A[1]) and its upper right corner has coordinates (A[2],A[3]).
B describes the second rectangle in the same way.


Your task is to determine how their intersection looks like.
There are four options:


If the rectangles have a non-zero area in common, return "rectangle".
Otherwise, if they have a common line segment with non-zero length, return "segment".
Otherwise, if they have a point in common, return "point".
Otherwise, return "none" (in all four cases, the quotes are just for clarity).


DEFINITION
Class:TwoRectangles
Method:describeIntersection
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string describeIntersection(vector <int> A, vector <int> B)


NOTES
-The Constraints guarantee that both rectangles lie in the first quadrant of the coordinate plane, and each rectangle has a positive area.


CONSTRAINTS
-A will contain exactly 4 elements.
-The elements of A will satisfy 0 <= A[0] < A[2] <= 1000 and 0 <= A[1] < A[3] <= 1000.
-B will contain exactly 4 elements.
-The elements of B will satisfy 0 <= B[0] < B[2] <= 1000 and 0 <= B[1] < B[3] <= 1000.


EXAMPLES

0)
{0,0,3,2}
{1,1,5,3}

Returns: "rectangle"

These two rectangles overlap partially:




1)
{0,0,5,3}
{1,2,2,3}

Returns: "rectangle"

The second rectangle is completely inside the first one.




2)
{1,1,6,2}
{3,2,5,4}

Returns: "segment"

The second rectangle sits on top of the first one.




3)
{0,1,2,3}
{2,0,5,2}

Returns: "segment"



4)
{0,0,1,1}
{1,1,5,2}

Returns: "point"



5)
{1,1,2,2}
{3,1,4,2}

Returns: "none"



*/
// END CUT HERE
#line 104 "TwoRectangles.cpp"

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

bool rectangle(vector<int> A, vector<int> B) {
    return (B[0] < A[2] && B[2] > A[0] && B[1] < A[3] && B[3] > A[1]);
}

bool segment(vector<int> A, vector<int> B) {
    int minX = min( min(A[0], A[2]), min(B[0], B[2]) );
    int maxX = max( max(A[0], A[2]), max(B[0], B[2]) );

    int y = A[1];
    int n = A.size();
    int cnt = 0;

    for (int i = 0; i < n; i += 2) {
        if (A[i+1] == y && minX <= A[i] && A[i] <= maxX)
            cnt++;
        else if (B[i+1] == y && minX <= B[i] && B[i] <= maxX)
            cnt++;
    }

    if (cnt == 4 && (maxX - minX < (A[2] - A[0]) + (B[2] - B[0]))) return true;

    int minY = min( min(A[1], A[3]), min(B[1], B[3]) );
    int maxY = max( max(A[1], A[3]), max(B[1], B[3]) );

    int x = A[0];
    cnt = 0;

    for (int i = 0; i < n; i += 2) {
        if (A[i] == x && minY <= A[i+1] && A[i+1] <= maxY)
            cnt++;
        else if (B[i] == x && minY <= B[i+1] && B[i+1] <= maxY)
            cnt++;
    }

    if (cnt == 4 && (maxY - minY < (A[3] - A[1]) + (B[3] - B[1]))) return true;

    return false;
}

bool equal_point(vector<int> A, vector<int> B) {
    int n = A.size();
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            if(A[i] == B[j] && A[i+1] == B[j+1])
                return true;
        }
    }
    return false;
}

string solve(vector<int> A, vector<int> B) {
    if(rectangle(A, B) || rectangle(B, A)) return "rectangle";
    if(segment(A, B) || segment(B, A)) return "segment";
    if(equal_point(A, B)) return "point";
    return "none";
}

class TwoRectangles {
public:
    string describeIntersection(vector <int> A, vector <int> B) {
        A.push_back(A[0]); B.push_back(B[0]);
        A.push_back(A[3]); B.push_back(B[3]);
        A.push_back(A[2]); B.push_back(B[2]);
        A.push_back(A[1]); B.push_back(B[1]);
        return solve(A, B);
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
			int A[]                   = {0,0,3,2};
			int B[]                   = {1,1,5,3};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {0,0,5,3};
			int B[]                   = {1,2,2,3};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,1,6,2};
			int B[]                   = {3,2,5,4};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {0,1,2,3};
			int B[]                   = {2,0,5,2};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {0,0,1,1};
			int B[]                   = {1,1,5,2};
			string expected__         = "point";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1,1,2,2};
			int B[]                   = {3,1,4,2};
			string expected__         = "none";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int A[]                   = {0,0,1,2};
			int B[]                   = {1,1,5,2};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
          int A[]                   = {0, 0, 4, 3};
          int B[]                   = {1, 1, 3, 2};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
