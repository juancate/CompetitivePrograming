#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int INF = int(1e9);
// BEGIN CUT HERE
#define D(x) cerr << #x << " = " << x << endl;
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  for (int i = 0; i < z.size(); i++)os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; foreach(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; foreach(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class LittleElephantAndString {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
  int getNumber(string A, string B);
};

// Algorithm: Two pointers

int a[30], b[30];

bool check() {
  for (int i = 0; i < 30; i++)
    if (a[i] != b[i])
      return false;
  return true;
}

int LittleElephantAndString::getNumber(string A, string B) {
  int n = A.size();

  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);

  for (int i = 0; i < n; i++) {
    a[A[i]-'A']++;
    b[B[i]-'A']++;
  }

  if (!check())
    return -1;

  for (int i = n-1, j = n-1; i >= 0; i--) {
    while (j >= 0 && (A[j] != B[i]))
      j--;
    if (j < 0)
      return i+1;
    j--;
  }

  return 0;
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
			string A                  = "ABC";
			string B                  = "CBA";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A                  = "A";
			string B                  = "B";
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A                  = "AAABBB";
			string B                  = "BBBAAA";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string A                  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string B                  = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string A                  = "A";
			string B                  = "A";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string A                  = "DCABA";
			string B                  = "DACBA";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string A                  = ;
			string B                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LittleElephantAndString().getNumber(A, B);
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
