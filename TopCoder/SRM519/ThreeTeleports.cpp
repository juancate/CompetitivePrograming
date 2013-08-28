// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are a frog. You live on an infinite lattice of grid points. For each pair of integers x, y there is a grid point with coordinates (x,y). At this moment, you sit on the grid point (xMe,yMe). You want to get home: to the grid point (xHome,yHome).
There are two ways in which you can travel. Your first option is jumping: if you are at (x,y), you can jump to one of the four neighboring grid points: (x+1,y), (x-1,y), (x,y+1), or (x,y-1). Each jump takes one second.
Your second option is using a teleport. There are three teleports in the entire world. Each of them connects two different grid points. If you are at one of the endpoints, you may activate the teleport and travel to its other endpoint. Traveling by teleport takes 10 seconds.
You are given ints xMe, yMe, xHome, yHome, and a vector <string> teleports that describes the three teleports. Each element of teleports will be a string containing four integers x1, y1, x2, and y2, separated by single spaces. These integers describe a teleport with endpoints at (x1,y1) and (x2,y2).
Your method must return the shortest time in which you can reach your home.

DEFINITION
Class:ThreeTeleports
Method:shortestDistance
Parameters:int, int, int, int, vector <string>
Returns:int
Method signature:int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports)


NOTES
-Traveling by a teleport is not mandatory. You may pass through its endpoint and decide not to use it.


CONSTRAINTS
-xMe, yMe, xHome, and yHome will all be between 0 and 1,000,000,000, inclusive.
-teleports will have exactly three elements.
-Each element of teleports will have the following format: "x1 y1 x2 y2" (quotes for clarity), where x1, y1, x2, and y2 are integers between 0 and 1,000,000,000, inclusive. The integers x1, y1, x2, and y2 will not contain unnecessary leading zeroes.
-All eight points (your location, the location of your home, and the six teleport endpoints) will be pairwise distinct.


EXAMPLES

0)
3
3
4
5
{"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}

Returns: 3

The frog must make at least 3 leaps. For example, from (3,3) to (3,4), then to (3,5), and finally to (4,5). The teleports are all too far away to be useful.

1)
0
0
20
20
{"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}

Returns: 14

The journey can be done in 40 jumps = 40 seconds, but there is a better solution: Make 2 jumps to get from (0,0) to (1,1), use the teleport to get to (18,20), and make 2 jumps to get to (20,20). This solution takes (2+10+2) = 14 seconds.

2)
0
0
20
20
{"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}

Returns: 14

The teleports may be used in either direction, and in any order.

3)
10
10
10000
20000
{"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}

Returns: 30



4)
3
7
10000
30000
{"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}

Returns: 117

Sometimes the best solution requires us to use more than one teleport. In this case, the optimal solution looks as follows:

Using jumps, travel to (3,10).
Use the first teleport.
Using jumps, travel from (5200,4900) to (5203,4845).
Use the third teleport.
Using jumps, travel from (12200,8701) to (12212,8699).
Use the second teleport.
Using jumps, travel from (9999,30011) to (10000,30000).



5)
0
0
1000000000
1000000000
{"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}

Returns: 36

Watch out for overflows. The correct return value will always fit into a int, but some other paths may be very long.

*/
// END CUT HERE
#line 110 "ThreeTeleports.cpp"

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

using namespace std;

class ThreeTeleports {
public:
  long long dist(int x1, int y1, int x2, int y2) {
    return abs(x2-x1) + abs(y2-y1);
  }
  // Floyd Warshall
  int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
    long long graph[8][8]; // eigth vertex

    fill(&graph[0][0], &graph[7][7], INF);

    graph[0][1] = graph[1][0] = dist(xMe, yMe, xHome, yHome);
    
    int n = teleports.size();
    int points[n+2][2];
    points[0][0] = xMe, points[0][1] = yMe;
    points[1][0] = xHome, points[1][1] = yHome;

    for(int i = 0, j = 2; i < n; i++, j+=2) {
      int xs, ys, xe, ye;
      istringstream(teleports[i]) >> xs >> ys >> xe >> ye;
      points[j][0] = xs, points[j][1] = ys;
      points[j+1][0] = xe, points[j+1][1] = ye;
    }

    // Build Graph with distance between every point
    REP(i,8) REP(j,8) 
      graph[i][j]=graph[j][i]=dist(points[i][0], points[i][1], points[j][0], points[j][1]);
    
    // set teleport distance
    for(int i = 0; 2*i + 2 < 8; i++) {
      graph[2*i + 2][2*i + 3] = graph[2*i + 3][2*i + 2] = 10LL;
    }
    
    REP(k,8) REP(i,8) REP(j,8) 
      graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    return graph[0][1];
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; string Arr4[] = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(1, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(2, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10000; int Arg3 = 20000; string Arr4[] = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 30; verify_case(3, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 10000; int Arg3 = 30000; string Arr4[] = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 117; verify_case(4, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1000000000; int Arg3 = 1000000000; string Arr4[] = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 36; verify_case(5, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	ThreeTeleports ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
