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
template<typename T> inline std::ostream& operator<<(std::ostream& os, const vector<T>& z) {  os << "[ \n";  REP(i,0,z.size())os << z[i] << ", \n" ;  return ( os << "]" << endl); }
template<typename T> inline std::ostream& operator<<(std::ostream& os, const set<T>& z) { os << "set( "; FOREACH(p,z)os << (*p) << ", " ; return ( os << ")" << endl); }
template<typename T,typename U> inline std::ostream& operator<<(std::ostream& os, const map<T,U>& z) { os << "{ "; FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;  return ( os << "}" << endl); }
// END CUT HERE

class ArcadeManao {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int shortestLadder(vector <string> level, int coinRow, int coinColumn);
};

int cr, cc, n, m;
bool used[55][55];

bool bfs(vector<string> level, int L) {
  vector<string> grid = level;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(level[i][j] == 'X') {
        for(int k = i+1; k < n && k < i+L; k++) {
          if(level[k][j] == '.')
            grid[k][j] = 'L';
        }
      }
    }
  }

  D(L);
  D(grid);

  queue< pair<int,int> > q;
  memset(used, false, sizeof used);

  q.push(make_pair(n-1,0));
  used[n-1][0] = true;

  while(!q.empty()) {
    pair<int,int> curr = q.front();
    q.pop();

    if(curr.first == cr && curr.second == cc) {
      D(used[10][21]);
      return true;
    }

    for(int k = -1; k <= 1; k += 2) {
      int nc = curr.second + k;
      if(nc >= 0 && nc < m && !used[curr.first][nc] && grid[curr.first][nc] == 'X') {
        q.push(make_pair(curr.first, nc));
        used[curr.first][nc] = true;
      }

      int nr = curr.first + k;
      if(nr >= 0 && nr < n && !used[nr][curr.second]) {
        if(grid[nr][curr.second] == 'X' || grid[nr][curr.second] == 'L') {
          q.push(make_pair(nr, curr.second));
          used[nr][curr.second] = true;
        }
      }
    }
  }

  return false;
}

int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn) {
  cr = coinRow-1;
  cc = coinColumn-1;
  n = level.size();
  m = level[0].size();

  if(coinRow == n) return 0;

  if(bfs(level, 1)) return 1;

  int lo = 0, hi = n;

  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if(bfs(level, mid)) hi = mid;
    else lo = mid+1;
  }
  return lo;
}

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
			string level[]            = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
			int coinRow               = 2;
			int coinColumn            = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string level[]            = {"XXXX",
 "...X",
 "XXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string level[]            = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
			int coinRow               = 1;
			int coinColumn            = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string level[]            = {"X"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string level[]            = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string level[]            = {"XXXXX.XXXXXXX.X..X.XX.XX.XX.XX.XX.X..X.",
                                   "..XX..XX.X...XXX.XX...XX.XX..XX..XX.XXX",
                                   "X.X....X.XXXXX...X.XXXX...X.X..XX...XXX",
                                   ".....X.X..X.X.XXX.XXXXX.X.X...XX.X.....",
                                   ".X.X.XX..X.X..XX..XXX..X....X.X.XX...X.",
                                   ".......X.XXX.....X..X.X.XXX..X...XXXX.X",
                                   ".X.....XXXX.XX.XXX...XXX..XX..XX.XXXX.X",
                                   "X....X.XXX..XX..XX.X.X...XX......X...XX",
                                   ".X..X.XXXX..X..X.....X....X...XX.X..X.X",
                                   "X.....X.X..XXXXX.XX..X....X..X.X.X...X.",
                                   "XXX.XX.XXXXX...XXX.XX.XXX..XXXX..XX.XXX",
                                   "X..XX.XX.XXXX..XX..XX.XX..X..X.XXXX.X.X",
                                   "X.X..XXX..X.X..XX..X..XX..X..X..X.XX..X",
                                   "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};
			int coinRow               = 8;
			int coinColumn            = 22;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
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

