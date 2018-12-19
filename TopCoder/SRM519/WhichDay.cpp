// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// This week there will be an important meeting of your entire department. You clearly remember your boss telling you about it. The only thing you forgot is the day of the week when the meeting will take place.

You asked six of your colleagues about the meeting. None of them knew the day when it will take place, but each of them remembered one day when it will not take place. The days they remembered were distinct. For a clever programmer like you, this was enough to determine the day of the meeting.

You are given a vector <string> notOnThisDay containing six weekdays when the meeting will not take place. Return the weekday of the meeting.

DEFINITION
Class:WhichDay
Method:getDay
Parameters:vector <string>
Returns:string
Method signature:string getDay(vector <string> notOnThisDay)


NOTES
-There are seven weekdays. Their names are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday".


CONSTRAINTS
-notOnThisDay will contain exactly 6 elements.
-Each element of notOnThisDay will be a name of a weekday (in the exact form specified in the Note above).
-No two elements of notOnThisDay will be equal.


EXAMPLES

0)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}

Returns: "Saturday"



1)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}

Returns: "Saturday"



2)
{"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}

Returns: "Wednesday"



3)
{"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}

Returns: "Thursday"



*/
// END CUT HERE
#line 61 "WhichDay.cpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

static string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                        "Friday", "Saturday", "Sunday"};

class WhichDay {
public:
  string getDay(vector <string> notOnThisDay) {
    set<string> dayset;
    REP(i,7) dayset.insert(days[i]);
    REP(i, notOnThisDay.size()) {
      dayset.erase(notOnThisDay[i]);
    }
    return *dayset.begin();
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Saturday"; verify_case(0, Arg1, getDay(Arg0)); }
	void test_case_1() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Saturday"; verify_case(1, Arg1, getDay(Arg0)); }
	void test_case_2() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Wednesday"; verify_case(2, Arg1, getDay(Arg0)); }
	void test_case_3() { string Arr0[] = {"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Thursday"; verify_case(3, Arg1, getDay(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	WhichDay ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
