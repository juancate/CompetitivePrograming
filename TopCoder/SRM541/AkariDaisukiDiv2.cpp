// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Consider the following function:
f(X) = Waai + X + Akari + X + Daisuki
Here, X is a string and + denotes string concatenation.
Waai, Akari and Daisuki are constant non-empty strings.



You are given a string S.
Compute and return the number of different tuples (Waai,Akari,Daisuki,X) such that f(X) equals S.


DEFINITION
Class:AkariDaisukiDiv2
Method:countTuples
Parameters:string
Returns:int
Method signature:int countTuples(string S)


NOTES
-Two tuples (A,B,C,D) and (E,F,G,H) are considered equal if and only if A=E, B=F, C=G, and D=H.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"topcoderdivtwo"

Returns: 2

The possible tuples of (Waai, Akari, Daisuki, X) are the following ones:

("t", "pc", "derdivtwo", "o")
("topco", "er", "ivtwo", "d")

("topc", "derdivtw", "", "o") is not allowed since Daisuki is empty.

1)
"foxciel"

Returns: 0

The answer can be zero.


2)
"magicalgirl"

Returns: 4



3)
"waaiusushioakariusushiodaisuki"

Returns: 75



4)
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

Returns: 8924



*/
// END CUT HERE
#line 79 "AkariDaisukiDiv2.cpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <limits>
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()
#define MP(a, b) make_pair(a, b)

#define ALL_BITS 0xFFFFFFFF
#define INF (int)(1e9)
#define INFLL (long long)(1e18)
#define EPS (1e-19)

using namespace std;
// BEGIN CUT HERE
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const pair<T,U>& z) { return ( os << "(" << z.first << ", " << z.second << ",)" ); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ ";  REP(i,0,z.size())os << z[i] << ", " ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; FOREACH(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class AkariDaisukiDiv2 {
  int n;
  set< pair< pair<string, string>, pair<string, string> > > sequences;

  bool valid(int i, int j, string S) {
    string str = S.substr(i+j);
    string k = S.substr(i, j);
    int pos, start = i + j;
    bool ok = false;
    //D(i); D(j);
    //if(i == 2 and j == 2) D(k);
    while((pos = str.find(k)) != string::npos) {
      if(i + j < start + pos + j and start + pos + j < n) {
        //D(pos); D(start);
        ok = true;
        sequences.insert( MP( MP(S.substr(0, i),  S.substr(i+j, pos))
                              , MP(S.substr(pos + start + j), k) ) );
      }
      start += pos + j;
      str = str.substr(pos + j);
    }
    return ok;
  }

public:
  int countTuples(string S) {
    sequences.clear();
    n = S.length();
    REP(i, 1, n) {
      int j = 1;
      while(valid(i, j, S)) j++;
    }
    //D(sequences);
    return (int)sequences.size();
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
			string S                  = "topcoderdivtwo";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "foxciel";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "magicalgirl";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "waaiusushioakariusushiodaisuki";
			int expected__            = 75;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			int expected__            = 8924;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv2().countTuples(S);
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
