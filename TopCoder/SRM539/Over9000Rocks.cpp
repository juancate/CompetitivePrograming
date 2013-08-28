// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You used to have only 30 rocks, but now you have plenty of them. In fact, we will assume that you have a potentially infinite supply of rocks. You would like to show that you own over 9000 rocks.
You have a set of boxes. You will choose a subset of those boxes and fill them with rocks so that the total number of rocks will be over 9000. Each box has a lower and an upper bound on the number of rocks it may contain.

You are given the vector <int>s lowerBound and upperBound. For each i, the values lowerBound[i] and upperBound[i] have the following meaning: If you decide to use box i, the number of rocks you may put inside the box must be between lowerBound[i] and upperBound[i], inclusive.

X is a positive integer that has two properties:

X is over 9000.
It is possible to select some of the boxes and fill them with appropriate numbers of rocks in such a way that the total number of rocks used is exactly X.

Compute and return the number of possible values of X.

DEFINITION
Class:Over9000Rocks
Method:countPossibilities
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countPossibilities(vector <int> lowerBound, vector <int> upperBound)


CONSTRAINTS
-lowerBound will contain between 1 and 15, elements, inclusive.
-upperBound will contain the same number of elements as lowerBound.
-Each element of lowerBound will be between 1 and 1,000,000 (10^6), inclusive.
-Each element i of upperBound will be between lowerBound[i] and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
{9000}
{9001}

Returns: 1

You can place 9000 or 9001 rocks in the single box. Of the allowed values, only 9001 is over 9000.

1)
{9000, 1, 10}
{9000, 2, 20}

Returns: 15

You have to choose box 0 and at least one other box, otherwise you have no chance of placing over 9000 rocks.
If you only choose boxes 0 and 1, you can place 9001 or 9002 rocks.
If you only choose boxes 0 and 2, you can place between 9010 and 9020 rocks, inclusive.
If you choose all three boxes, you can place between 9011 and 9022 rocks, inclusive.
Hence all possible values of X are 9001, 9002, and everything from 9010 to 9022, inclusive.

2)
{1001, 2001, 3001, 3001}
{1003, 2003, 3003, 3003}

Returns: 9



3)
{9000,90000,1,10}
{9000,90000,3,15}

Returns: 38



4)
{1,1,1,1,1,1}
{3,4,5,6,7,8}

Returns: 0



*/
// END CUT HERE
#line 80 "Over9000Rocks.cpp"

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
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FORAB(i,a,b) for(int i=a; i<b; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define ALL_BITS 0xFFFFFFFF
#define INF (std::numeric_limits<int>::max())
#define INFLL (std::numeric_limits<long long>::max())
#define EPS (1e-19)

using namespace std;

class Over9000Rocks {
public:
  int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
    set< pair<int, int> > intervals;
    int n = lowerBound.size();
    
    REP(subset, 0, (1 << n)) {
      int min = 0, max = 0;
      REP(j, 0, n) {
        if((subset & (1 << j)) != 0) {
          min += lowerBound[j];
          max += upperBound[j];
        }
      }

      min = std::max(min, 9001);
      if(min <= max) {
        intervals.insert( make_pair(min, max) );
      }
    }

    int last = 9001;
    int total = 0;
    FOREACH(interval, intervals) {
      last = std::max(last, interval->first);
      if(interval->second < last) continue;

      total += (interval->second - last) + 1;
      last = interval->second + 1;
    }
    return total;
  }
// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {9000, 1, 5}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {9000, 10, 6}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arg2 = 16; 
    verify_case(0, Arg2, countPossibilities(Arg0, Arg1)); 
  }
	void test_case_1() { int Arr0[] = {9000, 1, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9000, 2, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(1, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1001, 2001, 3001, 3001}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1003, 2003, 3003, 3003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9000,90000,1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9000,90000,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 38; verify_case(3, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countPossibilities(Arg0, Arg1)); }

// END CUT HERE

// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	Over9000Rocks ___test; 
	___test.run_test(0); 
} 
// END CUT HERE 
