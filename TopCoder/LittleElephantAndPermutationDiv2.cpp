#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int INF = int(1e9);
// BEGIN CUT HERE
#define REP(i,a,n) for (int i = a; i < n; i++)
#define D(x) cerr << #x << " = " << x << endl;
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  REP(i,0,z.size())os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; foreach(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; foreach(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class LittleElephantAndPermutationDiv2 {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    long long getNumber(int N, int K);
};

int a[11], b[11];
long long f[11];

long long LittleElephantAndPermutationDiv2::getNumber(int N, int K) {
  f[0] = 1;
  for (int i = 1; i <= N; i++)
    f[i] = i * f[i-1];

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    a[i] = i+1;
    b[i] = a[i];
  }

  do {
    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += max(a[i], b[i]);
    if (sum >= K)
      ans += f[N];
  } while (next_permutation(a, a+N));

  return ans;
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

	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) {
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
			int N                     = 1;
			int K                     = 1;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int K                     = 1;
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int K                     = 8;
			long long expected__      = 18;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int K                     = 47;
			long long expected__      = 13168189440000LL;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int K                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int K                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
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
