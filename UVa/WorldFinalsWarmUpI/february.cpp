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

#define INF 1<<30
#define EPS 1e-13

using namespace std;

bool leapYear(int year) {
  if(year % 100 == 0 and year % 400 == 0) return true;
  else if(year % 100 != 0 and year % 400 != 0 and year % 4 == 0) return true;
  return false;
}

int countleaps(int s, int e, int d) {
  if(s > e) return 0;
  return ((e - s)/d);
}

int findleap(int a, int d) {
  int i;
  for(i = a; !leapYear(i); i = i + d);
  return i;
}

int main() {
  int T;
  char m[30];
  scanf("%d\n", &T);
  REP(i,T) {
    int mdy1[3], mdy2[3];
    string s1, s2;
    scanf("%s %d, %d\n", m, &mdy1[1], &mdy1[2]);
    s1 = m;
    scanf("%s %d, %d\n", m, &mdy2[1], &mdy2[2]);
    s2 = m;

    int dct = 0, answer = 0;

    if(!leapYear(mdy1[2]) or (s1 != "January" and s1 != "February"))
      mdy1[2] = findleap(mdy1[2]+1, 1);

    if(leapYear(mdy2[2]) and (s2 != "January" and s2 != "February"));
    else if(leapYear(mdy2[2]) and (s2 == "February" and mdy2[1] == 29));
    else mdy2[2] = findleap(mdy2[2]-1, -1);
    
    // Find 100, count 400
    int cent1 = mdy1[2], cent2 = mdy2[2];
    if(cent1 % 100 != 0) cent1 = mdy1[2] + 100 - (mdy1[2] % 100);
    if(cent2 % 100 != 0) cent2 = mdy2[2] - (mdy2[2] % 100);

    int centleaps = 0;

    if(cent1 < cent2) {
      centleaps = countleaps(cent1, cent2, 100);
      centleaps -= countleaps(findleap(cent1, 100), findleap(cent2, -100), 400);
    } 
    else if(cent1 == cent2 and !leapYear(cent1)) centleaps++;

    if(mdy1[2] > mdy2[2]) answer = 0;
    else answer = countleaps(mdy1[2],mdy2[2], 4) - centleaps + 1;
    
    printf("Case %d: %d\n", (i+1), answer);
  }
}

