// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The Casket of Star (sic) is a device in the Touhou universe. Its purpose is to generate energy rapidly.
Initially it contains n stars in a row. The stars are labeled 0 through n-1 from the left to the right.
You are given a vector <int> weight, where weight[i] is the weight of star i.



The following operation can be repeatedly used to generate energy:

Choose a star x other than the very first star and the very last star.
The x-th star disappears.
This generates weight[x-1] * weight[x+1] units of energy.
We decrease n and relabel the stars 0 through n-1 from the left to the right.




Your task is to use the device to generate as many units of energy as possible. Return the largest possible total amount of generated energy.

DEFINITION
Class:CasketOfStarEasy
Method:maxEnergy
Parameters:vector <int>
Returns:int
Method signature:int maxEnergy(vector <int> weight)


CONSTRAINTS
-weight will contain between 3 and 10 elements, inclusive.
-Each element in weight will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: 12

We have only 2 choices:

Make the "2" disappear first, and "3" next. The total energy is 1*3 + 1*4 = 7.
Make the "3" disappear first, and "2" next. The total energy is 2*4 + 1*4 = 12.

So the answer is 12.

1)
{100,2,1,3,100}

Returns: 10400

We proceed as follows:
{100,2,1,3,100} => {100,1,3,100} => {100,3,100} => {100,100}
The total energy is 100*1 + 100*3 + 100*100 = 10400.

2)
{2,2,7,6,90,5,9}

Returns: 1818



3)
{477,744,474,777,447,747,777,474}

Returns: 2937051



4)
{1,1,1,1,1,1,1,1,1,1}

Returns: 8



*/
// END CUT HERE
#line 82 "CasketOfStarEasy.cpp"

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

class CasketOfStarEasy {
  int solve(vector<int> v, int sum) {
    int n = v.size();
    if(n == 2) return sum;
    int total = sum;
    for(int i = 1; i < n-1; i++) {
      int x = v[i];
      int y = v[i-1]*v[i+1];
      v.erase(v.begin()+i);
      total = max(total, solve(v, y+sum));
      v.insert(v.begin()+i, x);      
    }
    return max(sum, total);
  }
public:
	int maxEnergy(vector <int> weight) {
    return solve(weight, 0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, maxEnergy(Arg0)); }
	void test_case_1() { int Arr0[] = {100,2,1,3,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10400; verify_case(1, Arg1, maxEnergy(Arg0)); }
	void test_case_2() { int Arr0[] = {2,2,7,6,90,5,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1818; verify_case(2, Arg1, maxEnergy(Arg0)); }
	void test_case_3() { int Arr0[] = {477,744,474,777,447,747,777,474}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2937051; verify_case(3, Arg1, maxEnergy(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, maxEnergy(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	CasketOfStarEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
