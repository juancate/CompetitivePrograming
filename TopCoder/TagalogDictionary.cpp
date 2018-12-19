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

class TagalogDictionary {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    vector <string> sortWords(vector <string> words);
};

map<char,int> alpha;

void init() {
  alpha['a'] = alpha.size();  alpha['b'] = alpha.size();
  alpha['k'] = alpha.size();  alpha['d'] = alpha.size();
  alpha['e'] = alpha.size();  alpha['g'] = alpha.size();
  alpha['h'] = alpha.size();  alpha['i'] = alpha.size();
  alpha['l'] = alpha.size();  alpha['m'] = alpha.size();
  alpha['n'] = alpha.size();  alpha['?'] = alpha.size();
  alpha['o'] = alpha.size();  alpha['p'] = alpha.size();
  alpha['r'] = alpha.size();  alpha['s'] = alpha.size();
  alpha['t'] = alpha.size();  alpha['u'] = alpha.size();
  alpha['w'] = alpha.size();  alpha['y'] = alpha.size();
}

bool cmp(string a, string b) {
  int n = a.size(), m = b.size();
  for (int i = 0; i < min(n,m); i++) {
    if (alpha[a[i]] < alpha[b[i]])
      return true;
    if (alpha[a[i]] > alpha[b[i]])
      return false;
  }
  return n < m;
}

string f(string a, string r = "ng", string t = "?") {
  int pos;
  while ((pos = a.find(r)) != string::npos) {
    a = a.replace(pos, r.size(), t);
  }
  return a;
}

vector <string> TagalogDictionary::sortWords(vector <string> s) {
  init();
  int n = s.size();
  for (int i = 0; i < n; i++)
    s[i] = f(s[i]);

  sort(s.begin(),s.end(), cmp);

  for (int i = 0; i < n; i++)
    s[i] = f(s[i], "?", "ng");
  return s;
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

  template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
  template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

  int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
                string words[]            = {"abakada","alpabet","tagalog","ako"};
                string expected__[]       = {"abakada", "ako", "alpabet", "tagalog" };

                clock_t start__           = clock();
                vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 1: {
                string words[]            = {"ang","ano","anim","alak","alam","alab"};
                string expected__[]       = {"alab", "alak", "alam", "anim", "ano", "ang" };

                clock_t start__           = clock();
                vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 2: {
                string words[]            = {"siya","niya","kaniya","ikaw","ito","iyon"};
                string expected__[]       = {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" };

                clock_t start__           = clock();
                vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 3: {
                string words[]            = {"kaba","baka","naba","ngipin","nipin"};
                string expected__[]       = {"baka", "kaba", "naba", "nipin", "ngipin" };

                clock_t start__           = clock();
                vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 4: {
                string words[]            = {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"};
                string expected__[]       = {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", "ingkblot", "ingkigningg" };

                clock_t start__           = clock();
                vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 5: {
                string words[]            = {"silangang", "baka", "bada", "silang"};
                string expected__[]       = {"baka", "bada", "silang", "silangang" };

                clock_t start__           = clock();
                vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }

              // custom cases

              /*      case 6: {
                      string words[]            = ;
                      string expected__[]       = ;

                      clock_t start__           = clock();
                      vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                      return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
              /*      case 7: {
                      string words[]            = ;
                      string expected__[]       = ;

                      clock_t start__           = clock();
                      vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                      return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
              /*      case 8: {
                      string words[]            = ;
                      string expected__[]       = ;

                      clock_t start__           = clock();
                      vector <string> received__ = TagalogDictionary().sortWords(vector <string>(words, words + (sizeof words / sizeof words[0])));
                      return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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

