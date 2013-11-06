#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int INF = int(1e9);
// BEGIN CUT HERE
#define D(x) cerr << #x << " => " << x << endl;
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  for (int i = 0; i < z.size(); i++)os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; foreach(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; foreach(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class IncrementAndDoubling {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
  int getMin(vector <int> desiredArray);
};

int IncrementAndDoubling::getMin(vector <int> desiredArray) {
  int n = desiredArray.size();

  int sum = 0, max_div = 0;
  for (int i = 0; i < n; i++) {
    int curr = desiredArray[i];
    int op = 0, div = 0;
    while (curr >= 1) {
      if (curr & 1) curr--;
      else curr >>= 1, div++;
      op++;
    }
    max_div = max(max_div, div);
    sum += op;
    sum -= div;
  }
  sum += max_div;

  return sum;
}
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
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
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;

		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl;
			std::cerr << "    Received: " << received << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int desiredArray[]        = {2, 1};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int desiredArray[]        = {16, 16, 16};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int desiredArray[]        = {100};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int desiredArray[]        = {0, 0, 1, 0, 1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int desiredArray[]        = {123, 234, 345, 456, 567, 789};
			int expected__            = 40;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int desiredArray[]        = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7};
			int expected__            = 84;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int desiredArray[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int desiredArray[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int desiredArray[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = IncrementAndDoubling().getMin(vector <int>(desiredArray, desiredArray + (sizeof desiredArray / sizeof desiredArray[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
