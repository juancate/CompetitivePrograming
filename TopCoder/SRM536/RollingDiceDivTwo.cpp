// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Byteasar is playing a tabletop role-playing game with his friends. To determine the effectiveness of their heroes' actions the players use a rather unique set of dice which may have nonequal number of faces. Each die has between 1 and 9 faces, inclusive. If a die has m faces, they contain precisely all the values between 1 and m, inclusive. More precisely, for each k between 1 and m, inclusive, there is one face that shows exactly k pips. When a die is cast, every face has equal probability to come out on top.


Every time all the dice were thrown at once, Byteasar wrote down the numbers of pips visible on each of the topmost faces (in any order). The results of the i-th throw are given in throws[i]; the length of throws[i] is equal to the number of dice and each character of throws[i] denotes the number of pips visible on one of the topmost faces. For example, if throws[3][0]='7', this means that in throw 3 (0-based index) one of the dice showed exactly 7 pips on the top. Please note that the ordering of dice may be different for different throws.


Given the vector <string> throws containing Byteasar's notes, return the minimum possible total number of faces of all dice.

DEFINITION
Class:RollingDiceDivTwo
Method:minimumFaces
Parameters:vector <string>
Returns:int
Method signature:int minimumFaces(vector <string> rolls)


NOTES
-Please note that a die can have as few as one or two faces.


CONSTRAINTS
-rolls will contain between 1 and 50 elements, inclusive.
-rolls[0] will contain between 1 and 50 characters, inclusive.
-All elements of rolls will contain the same number of characters.
-Each character in each element of rolls will be one of '1'-'9'.


EXAMPLES

0)
{"137", "364", "115", "724"}

Returns: 14

In the first throw the numbers of pips on the topmost faces of the dice were 1, 3 and 7; in the second throw they were 3, 6 and 4, in the third they were 1, 1 and 5 and in the fourth roll they were 7, 2 and 4. The players may have used dice with 3, 4 and 7 faces, giving a total of 14 faces. No other possible set of dice has less faces in total.

1)
{"1112", "1111", "1211", "1111"}

Returns: 5

The players could have used three dice with one face each and one die with two faces.

2)
{"24412", "56316", "66666", "45625"}

Returns: 30

The players could have used five dice with six faces each.

3)
{"931", "821", "156", "512", "129", "358", "555"}

Returns: 19



4)
{"3", "7", "4", "2", "4"}

Returns: 7



5)
{"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"}

Returns: 176



*/
// END CUT HERE
#line 79 "RollingDiceDivTwo.cpp"

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
#define ALL(v) (v).begin(), (v).end()

using namespace std;

class RollingDiceDivTwo {
public:
  int minimumFaces(vector <string> rolls) {
    int n = rolls.size();
    int m = rolls[0].size();
    REP(i,n) sort(ALL(rolls[i]));
    int sum = 0;

    REP(i,m) {
      char maxval = rolls[0][i];
      REP(j, n) {
        if(maxval < rolls[j][i]) maxval = rolls[j][i];
      }
      sum += maxval - '0';
    }

    return sum;
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"137", "364", "115", "724"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, minimumFaces(Arg0)); }
	void test_case_1() { string Arr0[] = {"1112", "1111", "1211", "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, minimumFaces(Arg0)); }
	void test_case_2() { string Arr0[] = {"24412", "56316", "66666", "45625"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(2, Arg1, minimumFaces(Arg0)); }
	void test_case_3() { string Arr0[] = {"931", "821", "156", "512", "129", "358", "555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(3, Arg1, minimumFaces(Arg0)); }
	void test_case_4() { string Arr0[] = {"3", "7", "4", "2", "4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimumFaces(Arg0)); }
	void test_case_5() { string Arr0[] = {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 176; verify_case(5, Arg1, minimumFaces(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE 
int main()
{
	RollingDiceDivTwo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
