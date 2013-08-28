// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers. They fight against evil witches.



You are going to become a Magical Girl. You will start with M Life Points. M is also the maximal number of Life Points you may have. (I.e., if you gain some Life Points and your new total should exceed M, it will just become equal to M.) As soon as your Life Points drop to 0, you die.



Starting from day 1, at the beginning of each day you will lose one Life Point. The only way to gain Life Points is by defeating the evil witches. There are N witches, conveniently numbered 0 through N-1. Each of the witches will only appear once, for one day of your life. If you decide not to fight her, nothing will happen. If you decide to fight her, there are two possible outcomes: If you win, you will gain some Life Points and the witch disappears. If you lose, she will decrease your Life Points to zero and you die immediately. If multiple witches appear on the same day, you have to fight them one at a time: You pick the first witch to fight. If you defeat her, you gain the corresponding Life Points. Then you pick the second witch to fight, and so on, until you either defeat all the available witches or decide that you do not wish to fight any of the remaining ones.



You are given 
the int M, 
a vector <int> day,
a vector <int> win, and
a vector <int> gain.
Here, day[i] is the day on which the i-th witch appears, win[i] is the probability (as a percentage) that you will defeat the witch if you fight her, and gain[i] is the amount of Life Points you would gain for defeating the witch. Your goal is to maximize the expected day on which you die. Compute and return this expected value.


DEFINITION
Class:MagicalGirl
Method:maxExpectation
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain)


NOTES
-On each day, you first lose one Life Point, and only then are you allowed to fight the witches who appear on that day.
-The returned value must be accurate to within a relative or absolute error of 1e-9.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-M will be between 2 and 100,000, inclusive.
-day, win and gain will each contain exactly N elements.
-Each element of day will be between 1 and 5,000,000, inclusive.
-Each element of win will be between 0 and 100, inclusive.
-Each element of gain will be between 1 and M, inclusive.


EXAMPLES

0)
2
{1}
{75}
{1}

Returns: 2.5

Your life would look as follows: You start with 2 Life Points. Day 1 starts, you lose 1 Life Point and you have 1 Life Point left. Then a witch appears. You have a 75% probability of defeating her.

If you decide NOT to fight her, you will die on day 2. Here is what would happen if you DO fight her:

With probability 0.75, you will win and gain one more Life Point. You would then die on day 3.
With probability 0.25, you will die immediately, i.e., on day 1.

So if you decide to fight the witch, the expected day of your death is 0.75*3 + 0.25*1 = 2.5.
It is therefore a better strategy to fight the witch, and 2.5 is the correct answer.


1)
10
{5,5,5,5}
{100,100,100,100}
{1,1,1,1}

Returns: 14.0

You should fight all the witches since you can always win.

2)
10
{5,5,5,5,5}
{40,80,60,20,0}
{10,10,10,10,10}

Returns: 13.0

It is sufficient to fight a single witch, because the win would already restore your Life Points to M. The best option is to fight the one you are most likely to defeat. Note that fighting her gives you a better expectation than you get from not fighting any witches.

3)
2
{2}
{100}
{2}

Returns: 2.0

On each day, you first lose one Life Point, and only then are you allowed to fight the witches who appear on that day.

4)
20
{2,13,8,7,9,4,6,21}
{18,83,75,23,45,23,10,98}
{10,9,8,10,7,16,13,20}

Returns: 35.908



5)
11
{10,20,30,40,50,60,70,80,90}
{100,100,100,100,100,100,100,100,100}
{10,10,10,10,10,10,10,10,10}

Returns: 101.0



6)
100000
{1000000}
{100}
{100000}

Returns: 100000.0



*/
// END CUT HERE
#line 130 "MagicalGirl.cpp"

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

class MagicalGirl {
	public:
	double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {75}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.5; verify_case(0, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,100,100,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 14.0; verify_case(1, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {5,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,80,60,20,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,10,10,10,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 13.0; verify_case(2, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(3, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 20; int Arr1[] = {2,13,8,7,9,4,6,21}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {18,83,75,23,45,23,10,98}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,9,8,10,7,16,13,20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 35.908; verify_case(4, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 11; int Arr1[] = {10,20,30,40,50,60,70,80,90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,100,100,100,100,100,100,100,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,10,10,10,10,10,10,10,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 101.0; verify_case(5, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 100000; int Arr1[] = {1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 100000.0; verify_case(6, Arg4, maxExpectation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	MagicalGirl ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
