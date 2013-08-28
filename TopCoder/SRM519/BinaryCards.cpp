// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Karel is a robot. He has a set of 64 cards: for each x between 0 and 63, he has a card that is blank on one side and has 2^x dots on the other side.

Karel's cards are placed on a table. At any moment, the cards show some integer between 0 and (2^64)-1, inclusive. To read the number, you just count all the dots you see.

Karel is using the cards to count from A to B. That is, he is flipping some of the cards in such a way that the numbers A, A+1, ..., B appear in this order.

Of course, Karel is using the shortest possible sequence of flips. Additionally, he always flips the cards one at a time. Sometimes, changing the number from some Z to Z+1 requires Karel to flip more than one card. In that case, he flips the necessary cards ordered by the number of dots they have, starting with the one with the most dots.

For example, if A=6 and B=8, the following will happen:


In the beginning, the card with 4 dots and the card with 2 dots are showing the dots, all other cards are blank side up. This shows the number 6.
Karel flips the card with 1 dot. Now the number 7 is shown.
Karel flips the card with 8 dots.
Karel flips the card with 4 dots.
Karel flips the card with 2 dots.
Karel flips the card with 1 dot. Now the number 8 is shown and Karel is done.



Given are long longs A and B. Your method must return the largest number that will be shown at any moment during Karel's counting.


DEFINITION
Class:BinaryCards
Method:largestNumber
Parameters:long long, long long
Returns:long long
Method signature:long long largestNumber(long long A, long long B)


CONSTRAINTS
-A will be between 1 and 10^18, inclusive.
-B will be between A and 10^18, inclusive.


EXAMPLES

0)
6
6

Returns: 6



1)
6
7

Returns: 7



2)
6
8

Returns: 15

This is the example from the problem statement. When flipping cards to create the number 8 from the number 7, Karel starts by flipping the card with 8 dots. At this moment, the number shown on the cards is 15.

3)
1
11

Returns: 15



4)
35
38

Returns: 39



5)
1125899906842630
1125899906842632

Returns: 1125899906842639



*/
// END CUT HERE
#line 93 "BinaryCards.cpp"

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

class BinaryCards {
public:
  long long largestNumber(long long A, long long B) {
    for(int i = 62; i >= 0; i--)
      if((A ^ B) & (1LL << i)) // find leftmost bit difference
        return A | ((1LL << (i+1)) - 1); // take the number with all prev bits set
    return A; // if there is no diference A == B return any
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 6LL; long long Arg1 = 6LL; long long Arg2 = 6LL; verify_case(0, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 7LL; long long Arg2 = 7LL; verify_case(1, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 6LL; long long Arg1 = 8LL; long long Arg2 = 15LL; verify_case(2, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 11LL; long long Arg2 = 15LL; verify_case(3, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 35LL; long long Arg1 = 38LL; long long Arg2 = 39LL; verify_case(4, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 1125899906842630LL; long long Arg1 = 1125899906842632LL; long long Arg2 = 1125899906842639LL; verify_case(5, Arg2, largestNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	BinaryCards ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
