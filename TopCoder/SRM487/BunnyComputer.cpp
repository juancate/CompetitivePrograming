// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Bunnies like programming and they often practice for contests. 


There is a special computer named B-Computer, which all bunnies are eager to use. 
All bunnies want to solve a difficult problem using B-Computer. 
Because they type very fast, each of them wants to solve the problem according to the following process 
that consists of 3 stages (no delay is allowed between subsequent stages): 

	Use B-Computer for exactly one time unit. 
	Think and calculate on paper for exactly k time units, not using B-Computer. 
	Use B-Computer for exactly one time unit again to complete. 

B-Computer cannot be used by more than one bunny at the same time, 
but when a bunny is thinking and calculating on paper, another bunny may use B-Computer. 


A day is divided into a number of equal time units, 
and each time unit has an associated positive integer value called preference. 
You are given a vector <int> preference, which contains the preference values for a day. 
The number of elements in preference is the number of time units in the day, 
and the i-th element of preference is the preference of the i-th time unit. 


Bunnies want to design a B-Computer schedule for a single day 
so that the sum of preferences of time units in which one of them uses B-Computer is maximized. 
The schedule must be such that each bunny uses B-computer exactly as described above 
and both time units at which the same bunny uses B-computer are in the same day. 
Return the maximum possible sum of preferences. 
You can assume that there are infinitely many bunnies. 


DEFINITION
Class:BunnyComputer
Method:getMaximum
Parameters:vector <int>, int
Returns:int
Method signature:int getMaximum(vector <int> preference, int k)


CONSTRAINTS
-preference will contain between 1 and 50 elements, inclusive. 
-Each element of preference will be between 1 and 1,000,000, inclusive. 
-k will be between 1 and 50, inclusive. 


EXAMPLES

0)
{ 3, 1, 4, 1, 5, 9, 2, 6 }
2

Returns: 28

The sum is maximized when three bunnies use B-Computer as follows: 

	One bunny uses B-Computer during the 1-st time unit and again during the 4-th time unit. 
	One bunny uses B-Computer during the 3-rd time unit and again during the 6-th time unit. 
	One bunny uses B-Computer during the 5-th time unit and again during the 8-th time unit. 




1)
{ 3, 1, 4, 1, 5, 9, 2, 6 }
1

Returns: 31

2)
{ 1, 2, 3, 4, 5, 6 }
3

Returns: 14

3)
{ 487, 2010 }
2

Returns: 0

No bunnies can use B-Computer. 


*/
// END CUT HERE
#line 90 "BunnyComputer.cpp"

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

#define INF (1<<30)
#define INFLL (1LL<<62)
#define EPS (1e-19)

using namespace std;

class BunnyComputer {
public:
  int sumPairs(vector<int> p) {
    int n = p.size();
    int sum = accumulate(ALL(p), 0);
    if(n % 2 != 0) {
      int m = INF;
      for(int i = 0; i < n; i+=2) m = min(m, p[i]);
      sum -= m;
    }
    return sum;
  }

  int getMaximum(vector <int> preference, int k) {
    int sum = 0;
    int n = preference.size();
    for(int i = 0; i < k+1 and i < n; i++) {
      vector<int> p;
      for(int j = i; j < n; j += k + 1) p.push_back(preference[j]);
      sum += sumPairs(p);
    }
    return sum;
  }
// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 1, 4, 1, 5, 9, 2, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 28; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 3, 1, 4, 1, 5, 9, 2, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 31; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 14; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 487, 2010 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	BunnyComputer ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
