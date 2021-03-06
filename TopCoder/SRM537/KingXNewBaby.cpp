// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

After several years of waiting, King Dengklek and the queen finally had a baby. Now he is looking for a name for the newborn baby. According to the private rule of Kingdom of Ducks, the name of each member of the royal family must be such that:


It must consist of exactly eight letters. All letters must be lowercase ('a'-'z').
It must have exactly two vowels and six consonants. (Vowels are the letters 'a', 'e', 'i', 'o', and 'u'; the rest are consonants.)
The two vowels must be equal.


For example, "dengklek" is a valid name because it consists of exactly eight letters: six consonants and two identical vowels, 'e'.

You are given a String name. Please help the kingdom determine whether name is valid. Return "YES" if it is a valid name for King Dengklek's newborn baby, or "NO" otherwise.

DEFINITION
Class:KingXNewBaby
Method:isValid
Parameters:string
Returns:string
Method signature:string isValid(string name)


CONSTRAINTS
-name will contain between 1 and 50 characters, inclusive.
-Each character of name will be one of 'a'-'z'.



EXAMPLES

0)
"dengklek"

Returns: "YES"



1)
"gofushar"

Returns: "NO"

It has more than two vowels.

2)
"dolphinigle"

Returns: "NO"

It has more than eight letters.

3)
"mystictc"

Returns: "NO"

It has only one vowel.

4)
"rngringo"

Returns: "NO"

It has exactly two vowels, but they are not equal.

5)
"misof"

Returns: "NO"

It has less than eight letters.

6)
"metelsky"

Returns: "YES"



*/
// END CUT HERE
#line 85 "KingXNewBaby.cpp"

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

class KingXNewBaby {
public:
  string isValid(string name) {
    int v = 0, c = 0;
    char vowel = 'd';
    if(name.size() != 8) return "NO";

    REP(i, name.size()) {
      if(name[i] == 'a' or name[i] == 'e' or name[i] == 'i' or name[i] == 'o' or name[i] == 'u') {
        if(v == 0) vowel = name[i], v++;
        else if(v > 0 and vowel == name[i]) v++;
      } else {
        c++;
      }
    }
    return (v == 2 and c == 6)? "YES" : "NO";
  }
// BEGIN CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "dengklek"; string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { string Arg0 = "gofushar"; string Arg1 = "NO"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { string Arg0 = "dolphinigle"; string Arg1 = "NO"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { string Arg0 = "mystictc"; string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { string Arg0 = "rngringo"; string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { string Arg0 = "misof"; string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }
	void test_case_6() { string Arg0 = "metelsky"; string Arg1 = "YES"; verify_case(6, Arg1, isValid(Arg0)); }

// END CUT HERE

// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	KingXNewBaby ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
