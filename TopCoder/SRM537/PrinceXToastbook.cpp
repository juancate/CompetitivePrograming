// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Prince Gogo is the charming prince of the Kingdom of Ducks, where slimes and ducks live in peace and harmony.

Today, Prince Gogo purchased N toastbooks, numbered 0 through N-1. Each toastbook contains some knowledge and grants it to the person who eats it. It is known that no two toastbooks contain the same knowledge.

Initially, Gogo doesn't know any of the knowledge inside the toastbooks. He intends to eat them all and gain as many pieces of knowledge as possible. Furthermore, some of the books require a specific piece of knowledge in order to understand its knowledge. This will be given as a vector <int> prerequisite. If there is no required knowledge to understand the toastbook number i, prerequisite[i] will be -1.
Otherwise, prerequisite[i] will be the number of the toastbook that contains the knowledge necessary to understand book i. If Gogo eats some book x without having the required knowledge, he will not gain the knowledge inside the book, even if he later gains the knowledge from the book prerequisite[x].

Unfortunately, Gogo forgot to number the toastbooks when he purchased them. Hence, he is forced to eat all N toastbooks in a random order. Return the expected number of toastbooks that Gogo will understand.

DEFINITION
Class:PrinceXToastbook
Method:eat
Parameters:vector <int>
Returns:double
Method signature:double eat(vector <int> prerequisite)


NOTES
-The expected value of a random variable can be imagined as the average value of very many independent experiments.
-The returned value must have an absolute or relative error less than 10^-9.


CONSTRAINTS
-prerequisite will contain between 2 and 50 elements, inclusive.
-Each element of prerequisite will be between -1 and N-1, inclusive, where N is the number of elements in prerequisite.
-For all i, prerequisite[i] will not be i.


EXAMPLES

0)
{-1, 0}

Returns: 1.5

There are only two possible orders. If Gogo eats book 0 first, he
gains the knowledge in both books. If Gogo eats book 1 first, he
lacks the required knowledge to understand the book 1 when he read it. Hence, he will
only gain the knowledge in book 0. Therefore, the expected number
of books that Gogo will understand is the average of the two, which
is 1.5.

1)
{-1, 0, 1}

Returns: 1.6666666666666667

There are 6 possible orders. The number of books understood is as follows:
0, 1, 2: 3
0, 2, 1: 2
1, 0, 2: 1
1, 2, 0: 1
2, 0, 1: 2
2, 1, 0: 1

Hence, the expected number of books that Gogo will understand is their average, which is (3+2+1+1+2+1)/6 = 10/6.

2)
{1, -1, 1}

Returns: 2.0



3)
{1, 0}

Returns: 0.0

Each book has the other book as a prerequisite. Gogo will not be able to understand either one, regardless of the order in which he eats them.

4)
{-1, -1}

Returns: 2.0



*/
// END CUT HERE
#line 85 "PrinceXToastbook.cpp"

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

class PrinceXToastbook {
public:
  static const int MAXN = 52;
  
  double fact[MAXN];
  vector<int> G[MAXN];
  int indegree[MAXN], depth[MAXN];
  int n;

  void dfs(int node, int d) {
    depth[node] = d;
    FOREACH(v, G[node])
      dfs(*v, d+1);
  }

  double eat(vector <int> prerequisite) {
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAXN; i++) fact[i] = i * fact[i-1];

    n = prerequisite.size();

    REP(i,MAXN) G[i].clear();
    memset(indegree, 0, sizeof(indegree));
    memset(depth, -1, sizeof(depth));
    
    REP(i,n) if(prerequisite[i] != -1) {
      indegree[i]++;
      G[prerequisite[i]].push_back(i);
    }

    REP(i,n) if(indegree[i] == 0) dfs(i, 1);

    double sum = 0.0;
    
    REP(i,n) if(depth[i] != -1) sum += (1.0 / fact[depth[i]]);

    return sum;
  }
// BEGIN CUT HERE
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, eat(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.6666666666666667; verify_case(1, Arg1, eat(Arg0)); }
	void test_case_2() { int Arr0[] = {1, -1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(2, Arg1, eat(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, eat(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(4, Arg1, eat(Arg0)); }

// END CUT HERE

// END CUT HERE
};
// BEGIN CUT HERE 
int main()
{
	PrinceXToastbook ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
