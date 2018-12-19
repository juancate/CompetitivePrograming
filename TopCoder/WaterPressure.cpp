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

class WaterPressure {
  public:
    // BEGIN CUT HERE
    // Check variable limits, int sum of 1e9, etc.
    // END CUT HERE
    int howLong(vector <string> layout);
};

int n, m;
char g[55][55];
bool seen[55][55];

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, -1, 0, 1};

void print_g() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      fprintf(stderr, "%c ", g[i][j]);
    fprintf(stderr, "\n");
  }
}

bool finished() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(isdigit(g[i][j]))
        return false;
  return true;
}

bool is_valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m && isdigit(g[r][c]);
}

struct point {
  int r, c;
  point(int _r = 0, int _c = 0) {
    r = _r; c = _c;
  }

  bool operator<(const point& p) const {
    return g[r][c] < g[p.r][p.c];
  }

  bool operator==(const point& p) const {
    return r == p.r && c == p.c;
  }

  void print(FILE* f = stderr) const {
    fprintf(f, " r = %d, c = %d, g = %c\n", r, c, g[r][c]);
  }
};

int pfs() {
  set< point > q;

  for(int i = 0; i < 4; i++) {
    int nr = 0 + dr[i];
    int nc = 0 + dc[i];
    if(is_valid(nr, nc))
      q.insert(point(nr, nc));
  }

  int t, sq;
  t = 0, sq = 1;

  while(!q.empty()) {
    point curr = *q.begin();
    curr.print();

    int v = g[curr.r][curr.c] - '0';
    t = sq*v - 1; // check
    int water = t+1;
    double pressure = (double)water / (double)sq;
    D(water);

    set<point> next_pt;

    while(pressure >= v) {
      q.erase(q.begin());
      g[curr.r][curr.c] = '.';
      sq++;
      for(int i = 0; i < 4; i++) {
        int nr = curr.r + dr[i];
        int nc = curr.c + dc[i];

        if(is_valid(nr, nc)) {
          point next(nr, nc);
          if(!q.count(next))
            next_pt.insert(next); // check
        }
      }

      if(q.empty())
        break;

      curr = *q.begin();
      curr.print();
      v = g[curr.r][curr.c] - '0';
    }
    q.insert(ALL(next_pt));
  }
  print_g();

  if(finished())
    return t;
  return -1;
}

int WaterPressure::howLong(vector <string> layout) {
  memset(seen, 0, sizeof(seen));
  n = layout.size();
  m = layout[0].size();

  D(layout);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      g[i][j] = layout[i][j];

  return pfs();
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
                string layout[]           = {
                  ".0",
                  "0X"};
                int expected__            = 0;

                clock_t start__           = clock();
                int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                string layout[]           = {
                  ".0",
                  "00"};
                int expected__            = 1;

                clock_t start__           = clock();
                int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                string layout[]           = {
                  ".5",
                  "44"};
                int expected__            = 14;

                clock_t start__           = clock();
                int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                string layout[]           = {".23456789"};
                int expected__            = 71;

                clock_t start__           = clock();
                int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                string layout[]           = {
                  ".X0",
                  "X00"};
                int expected__            = -1;

                clock_t start__           = clock();
                int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 5: {
                string layout[]           = {
                  ".85773817518159249980260123498780838839X6384717463",
                  "242194445126058X5X93973323184X3X2747X842171X286218",
                  "598X67822897X5X61920060240170X31256497102692827551",
                  "54X36408X2548801X136636X63X9233X5949346X2274580162",
                  "5108021354X77X4477509918743895XXX159760734682X9115",
                  "50675439X0922X79916947371X01901217614357X0397201X3",
                  "27186118593416001273104X29X76977141883369859598888",
                  "80914X110594111X436841522027X668157791200228638293",
                  "940105447111X78X25011577574123524X04XXX51614492051",
                  "8804363635177X8246382862576X601870X74X139993345821",
                  "X48877009143171494700XX3X16138573259477742520850X9",
                  "1612588394913980186365912312794180464979928X986475",
                  "595353627322252222412X883094875X522435782213598237",
                  "17391130462739808923430X258255508957X4539278411137",
                  "161196X087X1959308152303433460329X6588920868810551",
                  "5X05897317154867X286045721X246725361349XX31742455X",
                  "X6356984801056259X735653998127X568670314628X485224",
                  "9320088X74859675156365X779X1X326767X79844419358X2X",
                  "501055497X39933X951356690965X4X0844917186293X57985",
                  "33413302X1903266448066612423X8038586XX5638903X7517",
                  "2976X251488X07X87464805678010167X32X54795816434863",
                  "18X8XX869283086X940798825X85739462998X3X3834428505",
                  "2555044879X7309586526260751345349591446476X7010X13",
                  "3233684019X20X770513442033X6950060849326X814045XX1",
                  "7378853595549545X9334157X55988471X21X3295375894550",
                  "7X9037779323X31807337002826035684828290777975X01X4",
                  "88X7X979X7X39506209854X7415XX8999X2253016X25035787",
                  "7683015X17268X16694392X6X101441658747937X198485622",
                  "1624X697868860600X030X577356X121482831384673XX7334",
                  "4662712538X13X4168850436576272047034855X5933218977",
                  "363X88X712383950892X775895613479X5287X01182X614158",
                  "0944515500373672425X6066X2108X3247524582717066X178",
                  "637664873632165059897471275828595X6527260271X84X40",
                  "305512X0X86260235207058X57705027964497905850617962",
                  "935138076111582XX0369X62229X178X921961753325422758",
                  "9987594X029815548549X858304X3181752985X5927X716348",
                  "631347X74X23510X703201850X965X8803X5794257X7X32012",
                  "597X2244071123X41X44196191328874040522673675346X00",
                  "9501X65935X9375252X55199X261467XXX8118871789524X62",
                  "732087503876417410X23X95740041509X58104X7543083124",
                  "175978X56605686460653815X08585X89XX137855313405573",
                  "51593131735080324921X2253417397314274XX231X5293926",
                  "XX778362173333574X333953005142250501X79X21757X1264",
                  "57350X7252505123850942501148X63526X106805090642546",
                  "2331X884X085X068X18X612328531670865X09525594XX98X6",
                  "6935X60327121102150643X49857600X77316813X362130791",
                  "331X29776535751774789772426596X1961969905180339X10",
                  "358X6622772195016X79558982X1024678439091439835013X",
                  "305362575995391477X2744272460098891730534152558XX1",
                  "28318306546365480X775289935065X4X48610794894231736"};
                int expected__            = 18566;

                clock_t start__           = clock();
                int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 6: {
                      string layout[]           = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      string layout[]           = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 8: {
                      string layout[]           = ;
                      int expected__            = ;

                      clock_t start__           = clock();
                      int received__            = WaterPressure().howLong(vector <string>(layout, layout + (sizeof layout / sizeof layout[0])));
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

