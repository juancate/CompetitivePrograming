// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to cut and eat cake. He used a rectangular baking dish to make a cake. The dish is divided into a grid of unit square cells. Initially, all the cells contained the cake.

Gogo's friend John wanted to eat the cake. Gogo gave John a rectangular cake cutter with the following properties:

The cake cutter is divided into a grid of cells. The cells are of the same size as the cells of the dish.
The cake cutter contains cells of two types: used cells and ignored cells.
Each of the first row, the last row, the first column, and the last column of the cutter contains at least one used cell.

When used, the cake cutter must be placed on the dish according to the following rules:

Each cell of the cutter must contain a single cell of the dish.
It is not allowed to flip or rotate the cutter. Rows and columns of the cutter must correspond to some consecutive rows and some consecutive columns of the dish in the given orientation. (See the last two examples.)
Each used cell of the cutter must be placed onto a cell that still contains cake. The ignored cells may be placed onto any cells.


When the cake cutter is used in the way described above, it removes the cake from all the used cells. John may have used the cake cutter multiple times, one after another.

After John went home, Gogo examined the cake that remained in the dish. He now wants to check whether John really cut the cake according to the above rules. You are given vector <string>s cake and cutter. The remaining cake is described by cake. More precisely, cake[i][j] is 'X' if the cell in the i-th row and j-th column of the dish still contains cake; otherwise cake[i][j] is '.' (a period). The cake cutter is described by cutter. More precisely, cutter[i][j] is '.' (a period) if the cell in the i-th row and j-th column of the cutter is used, and 'X' if the cell is ignored.

Return "YES" (quotes for clarity) if it is possible that John only ate the cake by using the cutter in the way described above. Return "NO" otherwise.

DEFINITION
Class:GogoXCake
Method:solve
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string solve(vector <string> cake, vector <string> cutter)


NOTES
-The used cells in the cutter do not have to be contiguous.


CONSTRAINTS
-cake will contain between 1 and 50 elements, inclusive.
-Each element of cake will contain between 1 and 50 characters, inclusive.
-All elements of cake will contain the same number of characters.
-Each character in each element of cake will be either '.' or 'X'.
-There will be at least one '.' in cake
-cutter will contain between 1 and R elements, inclusive, where R is the number of elements in cake.
-Each element of cutter will contain between 1 and C characters, inclusive, where C is the number of characters in each element of cake.
-All elements of cutter will contain the same number of characters.
-Each character in each element of cutter will be either '.' or 'X'.
-Each of the first row, the first column, the last row, and the last column of the cutter will contain at least one '.'.


EXAMPLES

0)
{"X.X"
,"..."
,"..."
,"X.X"}
{".X"
,".."
,"X."}

Returns: "YES"



1)
{"..XX"
,"...X"
,"X..."
,"XX.."}
{".."
,".."}

Returns: "NO"



2)
{"...X..."}
{"..."}

Returns: "YES"



3)
{".X."
,"X.X"
,".X."}
{"."}

Returns: "YES"



4)
{"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}
{".X."
,"XXX"
,".X."}

Returns: "NO"



5)
{".."
,"X."
,".X"}
{".."
,".X"
,"X."}

Returns: "NO"

You may not flip the cutter.

6)
{"X.."
,".XX"
,".XX"}
{".XX"
,".XX"
,"X.."}

Returns: "NO"

You may not rotate the cutter.

*/
// END CUT HERE
#line 136 "GogoXCake.cpp"

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
typedef pair<int, int> ii;

class GogoXCake {
  int n, m;
  bool solution(vector<string> cake) {
    REP(i, n) REP(j, m) if(cake[i][j] != 'X') return false;
    return true;
  }

  ii topleftmost(vector<string> v) {
    ii point = ii(-1, -1);
    REP(i, v.size()) {
      int j = v[i].find(".");
      if(j != string::npos) {
        point = ii(i, j);
        break;
      }
    }
    return point;
  }

  bool valid(int k, int l, int n, int m) {
    return (k >= 0 and k < n and l >= 0 and l < m);
  }
public:
	string solve(vector <string> cake, vector <string> cutter) {
    n = cake.size(), m = cake[0].size();
    ii tlcutter = topleftmost(cutter);
		while(true) {
      if(solution(cake)) return "YES";

      ii tlcake = topleftmost(cake);
      
      int k = tlcake.first;
      for(int i = 0; i < cutter.size(); i++, k++) {
        int l = tlcake.second - tlcutter.second;
        for(int j = 0; j < cutter[0].size(); j++, l++) {
          if(cutter[i][j] == '.')
            if(valid(k, l, n, m) and cake[k][l] == '.')
              cake[k][l] = 'X';
            else
              return "NO";
        }
      }
    }
	}
	
// BEGIN CUT HERE




















	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    string Arr0[] = {"X.", ".X"};/*{"X.X"
                     ,"..."
                     ,"..."
                     ,"X.X"}; */
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {".X", "X."};/*{".X"
                     ,".."
                     ,"X."}; */
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arg2 = "NO"/*"YES"*/; verify_case(0, Arg2, solve(Arg0, Arg1)); 
  }
	
void test_case_1() { string Arr0[] = {"..XX"
,"...X"
,"X..."
,"XX.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".X."
,"X.X"
,".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X."
,"XXX"
,".X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".."
,"X."
,".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".X"
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(5, Arg2, solve(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"X.."
,".XX"
,".XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".XX"
,".XX"
,"X.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(6, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	GogoXCake ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
