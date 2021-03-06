// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Saburo found two interesting positive integers: A and B.

On the next day, Saburo met Jiro and wanted to tell him the two integers. However, he managed to forget their values. All Saburo could remember was their greatest common divisor G and their least common multiple L.

You are given two long longs: G and L. Find the original integers A and B, and return the value of A+B. If there are multiple pairs of A and B that correspond to G and L, pick the one that minimizes A+B. If it is impossible to find such A and B (i.e., Saburo made a mistake somewhere), return -1.

DEFINITION
Class:FoxAndGCDLCM
Method:get
Parameters:long long, long long
Returns:long long
Method signature:long long get(long long G, long long L)


NOTES
-The greatest common divisor of two integers a and b is the largest positive integer that divides both a and b without any remainder.
-The least common multiple of two integers a and b is the smallest positive integer that is a multiple of both a and b.


CONSTRAINTS
-G will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-L will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
20

Returns: 14

The possible pairs of A and B are {2, 20} and {4, 10}. We need to pick {4, 10} since 4+10 is the smallest sum of A and B.

1)
5
8

Returns: -1

There are no pairs of A and B such that their greatest common divisor is 5 and their least common multiple is 8.

2)
1000
100

Returns: -1



3)
100
1000

Returns: 700



4)
10
950863963000

Returns: 6298430



*/
// END CUT HERE
#line 73 "FoxAndGCDLCM.cpp"

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

class FoxAndGCDLCM {
public:
  long long get(long long G, long long L) {
    if(L % G != 0) return -1;

    long long d = L / G;
    long long ans = 1LL<<62;

    for(long long i = (long long)sqrt(d); i >= 1; i--) {
      if(d % i == 0) {
        if(__gcd(i, d / i) == 1) ans = min(ans, (i + (d/i))*G);
      }
    }
    return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 20LL; long long Arg2 = 14LL; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 8LL; long long Arg2 = -1LL; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1000LL; long long Arg1 = 100LL; long long Arg2 = -1LL; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 100LL; long long Arg1 = 1000LL; long long Arg2 = 700LL; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 10LL; long long Arg1 = 950863963000LL; long long Arg2 = 6298430LL; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	FoxAndGCDLCM ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
