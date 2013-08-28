// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony.

One day, the queen of the kingdom challenged Mr. Dengklek with a perplexing puzzle: she gave Mr. Dengklek an N × M board made of wood that consists of N*M squares. She then asked Mr. Dengklek to paint the squares according to these rules:


Each square must be either colored or empty.
Each colored square must have an even number of adjacent colored squares. Two squares are adjacent if they share a side.

For example, here is one valid solution for N=4, M=7:



In the above image, black squares denote empty squares and brown squares denote colored squares.

Of course, finding one solution to the puzzle is easy: we do not color anything. Instead, the queen asked Mr. Dengklek a much harder question: to count all valid solutions of the puzzle. Help Mr. Dengklek count the solutions and return the result modulo 1,000,000,007. Two solutions are different if there is a square that is colored in one solution and not colored in the other solution.

DEFINITION
Class:DengklekPaintingSquares
Method:numSolutions
Parameters:int, int
Returns:int
Method signature:int numSolutions(int N, int M)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 1 and 8, inclusive.


EXAMPLES

0)
1
1

Returns: 2

Either Mr. Dengklek colors the square, or he does not. Both choices produce a valid solution.

1)
2
2

Returns: 8

Here are the 8 valid solutions:



2)
1
3

Returns: 5



3)
47
7

Returns: 944149920



*/
// END CUT HERE
#line 72 "DengklekPaintingSquares.cpp"

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

class DengklekPaintingSquares {
	public:
	int numSolutions(int N, int M) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 7; int Arg2 = 944149920; verify_case(3, Arg2, numSolutions(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	DengklekPaintingSquares ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
