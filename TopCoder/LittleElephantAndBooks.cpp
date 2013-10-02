#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int INF = int(1e9);
// BEGIN CUT HERE
#define D(x) cerr << #x << " = " << x << endl;
// END CUT HERE

class LittleElephantAndBooks {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int getNumber(vector <int> pages, int number);
};

int LittleElephantAndBooks::getNumber(vector <int> pages, int number) {
  int n = pages.size();
  sort(pages.begin(), pages.end());

  int sum = 0;
  for (int i = 0; i < number-1; i++)
    sum += pages[i];
  sum += pages[number];
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
			int pages[]               = {1, 2};
			int number                = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int pages[]               = {74, 7, 4, 47, 44};
			int number                = 3;
			int expected__            = 58;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int pages[]               = {3, 1, 9, 7, 2, 8, 6, 4, 5};
			int number                = 7;
			int expected__            = 29;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int pages[]               = {74, 86, 32, 13, 100, 67, 77};
			int number                = 2;
			int expected__            = 80;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int pages[]               = ;
			int number                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int pages[]               = ;
			int number                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int pages[]               = ;
			int number                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
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
