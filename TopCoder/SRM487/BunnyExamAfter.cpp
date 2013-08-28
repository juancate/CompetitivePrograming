// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Bunnies like programming but they don't like programming exams. 


Three bunnies, Black, Gray and White, had completed their final exam. 
While they were discussing the problems, the Professor came and said, "Black, you got zero points! 
To improve your knowledge, write a program which calculates the maximum possible sum of points 
that Gray and White could have gotten." 


There were N problems in the exam. 
All bunnies were presented with the same problems. 
For each problem, they had to write an uppercase letter ('A' - 'Z') as its answer. 
Only one letter is considered to be a correct answer for a problem, 
and all other 25 letters are considered to be incorrect answers. 
Each correct answer was worth 1 point, 
so the number of points received by a bunny was equal to the number of problems she answered correctly. 


You are given three strings black, gray and white 
representing the answers Black, Gray and White wrote, respectively. 
Each contains exacty N characters and the i-th character represents the answer for the i-th problem of the respective bunny. 
Return the maximum possible sum of points that Gray and White could have gotten for the exam, 
considering all possible answers that leave Black with 0 points. 


DEFINITION
Class:BunnyExamAfter
Method:getMaximum
Parameters:string, string, string
Returns:int
Method signature:int getMaximum(string black, string gray, string white)


CONSTRAINTS
-black will contain between 1 and 50 characters, inclusive. 
-black, gray and white will contain the same number of characters. 
-Each character in black, gray and white will be an uppercase letter ('A' - 'Z'). 


EXAMPLES

0)
"ABC"
"ABC"
"ABC"

Returns: 0

We know that all of Black's answers were incorrect, and since Gray and White had the exact same answers as Black, 
they too got 0 points. 


1)
"A"
"B"
"B"

Returns: 2

The correct answer for the only problem is one of 'B' - 'Z'. 
If it is 'B', Gray and White will each get 1 point and the total is 2 points. 
If it is one of 'C' - 'Z', Gray and White will each get 0 points and the total is 0 points. 


2)
"ABC"
"PQR"
"XYZ"

Returns: 3

Gray might get 3 points and White might get 3 points, but the total will not exceed 3 points. 


3)
"AAAAA"
"AABBB"
"BBBAA"

Returns: 6

4)
"TOPCODER"
"TOPBUNNY"
"THEHONEY"

Returns: 9

*/
// END CUT HERE
#line 95 "BunnyExamAfter.cpp"

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

#define INF (1<<30)
#define INFLL (1LL<<62)
#define EPS (1e-19)

using namespace std;

class BunnyExamAfter {
public:
  int getMaximum(string black, string gray, string white) {
    int sum = 0;
    int n = black.size();

    REP(i,n) {
      if(gray[i] != black[i] or white[i] != black[i]) {
        sum++;
        if(gray[i] == white[i]) sum++;
      }
    }    

    return sum;
  }
// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABC"; string Arg1 = "ABC"; string Arg2 = "ABC"; int Arg3 = 0; verify_case(0, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "A"; string Arg1 = "B"; string Arg2 = "B"; int Arg3 = 2; verify_case(1, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ABC"; string Arg1 = "PQR"; string Arg2 = "XYZ"; int Arg3 = 3; verify_case(2, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "AAAAA"; string Arg1 = "AABBB"; string Arg2 = "BBBAA"; int Arg3 = 6; verify_case(3, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "TOPCODER"; string Arg1 = "TOPBUNNY"; string Arg2 = "THEHONEY"; int Arg3 = 9; verify_case(4, Arg3, getMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE

// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	BunnyExamAfter ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
