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

class RobotHerbDiv2 {
public:
// BEGIN CUT HERE
// Check variable limits, int sum of 1e9, etc.
// END CUT HERE
    int getdist(int T, vector <int> a);
};

void move(int times, int& x, int& y, int& d) {
    switch(d) {
        case 0: y += times; break;
        case 1: x += times; break;
        case 2: y -= times; break;
        case 3: x -= times;
    }
    int m = times % 4;
    d = (d + m) % 4;
}

int RobotHerbDiv2::getdist(int T, vector <int> a) {
    int x = 0, y = 0, dir = 0; // dir: 0 ^ 1 > 2 v 3 <
    int n = a.size();
    while(T--) {
        for(int i = 0; i < n; i++) {
            move(a[i], x, y, dir);
        }
    }

    return abs(x) + abs(y);
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
                        int T                     = 1;
                        int a[]                   = {1,2,3};
                        int expected__            = 2;

                        clock_t start__           = clock();
                        int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int T                     = 100;
                        int a[]                   = {1};
                        int expected__            = 0;

                        clock_t start__           = clock();
                        int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int T                     = 5;
                        int a[]                   = {1,1,2};
                        int expected__            = 10;

                        clock_t start__           = clock();
                        int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int T                     = 100;
                        int a[]                   = {400000};
                        int expected__            = 40000000;

                        clock_t start__           = clock();
                        int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int T                     = ;
                            int a[]                   = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int T                     = ;
                            int a[]                   = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int T                     = ;
                            int a[]                   = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = RobotHerbDiv2().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
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
