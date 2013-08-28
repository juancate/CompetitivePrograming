// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are N fish and N+1 buoys in a small pond. Mr. Jeipouju wants to capture some of the fish.

In this problem, regard the pond as a 2-dimensional Cartesian plane (as seen from above). Each fish and each buoy is a point on the plane.
The buoys are lined up on x axis and numbered 0 to N from left to right.
There is exactly one fish between each two neighboring buoys.  The fish are numbered 0 to N-1 from left to right.
For the purpose of this problem we will assume that the fish are staying on their spots without any movement.
The exact coordinates of the fish and the buoys do not matter.  See the following image for clarity.



You are given a string fish with N characters. Each character of fish is either letter 'O' or 'X' or '*'. If fish[i] is 'O', it represents that he must capture fish i. If fish[i] is 'X', he must not capture fish i. If fish[i] is '*', he does not care whether he capture fish i or not.

To capture the fish, Mr. Jeipouju wants to set up a net in the pond so that the net will separate the caught fishes from the uncaught ones.
From above, the net must be a closed curve in our plane.
Furthermore, this closed curve must satisfy the following conditions:


  The net is not allowed to pass through any of the fish.
  The net is not allowed to touch or intersect itself.
  The net may only cross the x axis at points that contain the buoys. The net is not allowed to touch the x axis without crossing it.
  The net must cross the x axis at least twice.
  The fish Mr. Jeipouju wants to capture and the fish he wants not to capture must be separated by the net.
  That is, either all fish marked with 'X' are to be inside the net and all fish marked with 'O' outside, or vice versa. 
  The fish marked '*' may be anywhere, possibly some of them inside and some outside the net.


The following image shows some examples of valid and invalid net placements: 4 nets to the left are valid and 5 nets to the right are invalid.



A net can be encoded into a sequence using the following algorithm:

  Start anywhere on the net, but not on a buoy.
  Walk along the net until you reach your starting point again.
  During the walk, each time you encounter a buoy, write down its number and the halfplane in which you are moving away from the x axis. (The halfplane is "+" if after visiting the buoy your y coordinate is positive and "-" if it is negative.)

In this way you will obtain some sequence (buoy1,side1,...,buoyK,sideK).
Two nets are considered the same if they can be encoded to the same sequence.

Mr. Jeipouju wants to know whether the number of different nets is odd or even.
Your method must return the number of different nets, modulo 2.


DEFINITION
Class:CaptureFish
Method:getParity
Parameters:string
Returns:int
Method signature:int getParity(string fish)


CONSTRAINTS
-fish will contain between 1 and 50 characters, inclusive.
-Each character of fish will be either letter 'O' or 'X' or '*'.
-fish will contain at least one 'O' character.


EXAMPLES

0)
"OXOXO"

Returns: 0

In this case, there are 5 fish. There are 8 ways to separate them.



1)
"OO"

Returns: 1

There is only one valid net and it looks as follows:



Two things to notice:
First, the net does not have to pass through all the buoys.
Second, it is allowed to have no fish at all at either side of the net.

2)
"**OX**"

Returns: 0



3)
"O***O***O***O"

Returns: 1



*/
// END CUT HERE
#line 102 "CaptureFish.cpp"

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
#include <limits>
#include <complex>

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FORAB(i,a,b) for(int i=a; i<b; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define INF (std::numeric_limits<int>::max())
#define INFLL (std::numeric_limits<long long>::max())
#define EPS (1e-19)

using namespace std;

class CaptureFish {
	public:
	int getParity(string fish) {
		
	}
// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "OXOXO"; int Arg1 = 0; verify_case(0, Arg1, getParity(Arg0)); }
	void test_case_1() { string Arg0 = "OO"; int Arg1 = 1; verify_case(1, Arg1, getParity(Arg0)); }
	void test_case_2() { string Arg0 = "**OX**"; int Arg1 = 0; verify_case(2, Arg1, getParity(Arg0)); }
	void test_case_3() { string Arg0 = "O***O***O***O"; int Arg1 = 1; verify_case(3, Arg1, getParity(Arg0)); }

// END CUT HERE

// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	CaptureFish ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
