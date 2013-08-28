// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// During the girl sleepovers, Elly and her friends happen to play games that involve the consumption of fluids. For the purpose of this problem, we will assume that the fluids consumed are apple juice and orange juice. (This does not necessarily correspond to reality.)

One of these games is the following:
Five girls sit down in a circle. We will label the girls 0 through 4 in the order in which they sit. Note that the girls 0 and 4 sit next to each other.
At the beginning of the game, each girl i picks a positive integer numbers[i] between one and ten thousand.

The game then proceeds in rounds.
Each round involves two girls that sit next to each other.
Both girls must have positive integers at the beginning of the round.
There are two possible actions they may perform:

If both their integers are odd, they may perform the "apple action":
they subtract 1 from each of their integers, and they share a glass of apple juice.
They may always perform the "orange action": They divide both their integers by 2
(rounding down, if the result is not an integer) and share a glass of orange juice.

The girls win the game if all of their numbers reach zero.


Elly once observed five of her friends playing this game. Elly recorded the game on a piece of paper:
For each round, she wrote down the pair of girls that played in that round and the drink they chose. (The order in which she wrote down the two girls does not matter.)
If the girls won the game, Elly gives the paper to you, otherwise she throws it away.

You are given the vector <int> numbers containing the integers the girls selected
at the beginning of the game. Let X be the count of different ways in which the girls could
have won the game. In other words, X is the number of different papers Elly could have written down and given to you. Your method must return this value modulo 1,000,000,007.

DEFINITION
Class:EllysFiveFriends
Method:getZero
Parameters:vector <int>
Returns:int
Method signature:int getZero(vector <int> numbers)


CONSTRAINTS
-numbers will contain exactly 5 elements.
-Each element of numbers will be between 1 and 10000, inclusive.


EXAMPLES

0)
{5, 1, 1, 2, 3}

Returns: 10

One of the ways in which the girls can win the game:

Girls 0 and 1 drink orange juice. New integers: {2, 0, 1, 2, 3}.
Girls 2 and 3 drink orange juice. New integers: {2, 0, 0, 1, 3}.
Girls 3 and 4 drink apple juice.  New integers: {2, 0, 0, 0, 2}.
Girls 0 and 4 drink orange juice. New integers: {1, 0, 0, 0, 1}.
Girls 0 and 4 drink apple juice.  New integers: {0, 0, 0, 0, 0}.

A different way of winning the game has the same first four steps, and then in step 5 girls 0 and 4
drink orange juice. Note that in step 2 girls 2 and 3 are not allowed to choose apple juice, as at
that time at least one of their integers is even.

1)
{2, 1, 1, 1, 2}

Returns: 0

Here the girls cannot win the game at all.

2)
{3, 4, 1, 4, 5}

Returns: 520

Even with small numbers the answer can be rather big.

3)
{42, 666, 1337, 666, 42}

Returns: 549119981

Don't forget to use modular arithmetics.

4)
{8792, 9483, 6787, 9856, 6205}

Returns: 165501353

An almost maximal test case.

5)
{10000, 10000, 10000, 10000, 10000}

Returns: 952019520

The maximal test case.

*/
// END CUT HERE
#line 101 "EllysFiveFriends.cpp"

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

class EllysFiveFriends {
	public:
	int getZero(vector <int> numbers) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, getZero(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 1, 1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getZero(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 1, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 520; verify_case(2, Arg1, getZero(Arg0)); }
	void test_case_3() { int Arr0[] = {42, 666, 1337, 666, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 549119981; verify_case(3, Arg1, getZero(Arg0)); }
	void test_case_4() { int Arr0[] = {8792, 9483, 6787, 9856, 6205}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 165501353; verify_case(4, Arg1, getZero(Arg0)); }
	void test_case_5() { int Arr0[] = {10000, 10000, 10000, 10000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 952019520; verify_case(5, Arg1, getZero(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	EllysFiveFriends ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
