#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
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

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

// Problem: 11660 - Look-and-Say sequences
// Algorithm: Greedy.
// Description: Check limits of j to optimize

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;


string generate(string a, int n) {
  for(int i = 0; i < n; i++) {
    string temp = "";
    char current = a[0];
    int pos = 0;
    int cnt = 1;

    while(pos < a.size() && temp.size() <= 1000) {
      pos++;
      if(a[pos] == current) {
        cnt++;
      } else {
        temp += cnt + '0';
        temp += current;
        current = a[pos];
        cnt = 1;
      }
    }
    a = temp;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  string a;
  int i, j;
  while(cin >> a >> i >> j && (i|j) && a != "0") {
    string ans = generate(a, i-1);
    cout << ans[j-1] << endl;
  }
}

