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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int64 count(int64 x) {
    if(x < 10) return x;

    stringstream ss;
    ss << x;

    string s = ss.str();
    int n = s.size();

    int64 cnt = x / 10 - 1;

    if(s[0] <= s[n-1]) cnt++;

    cnt += 9;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);

    int64 l, r;
    cin >> l >> r;

    cout << (count(r) - count(l-1)) << endl;
}

