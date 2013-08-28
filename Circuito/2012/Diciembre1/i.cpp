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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

inline int sqr(int x) {
    return x*x;
}

int main() {
    ios_base::sync_with_stdio(false);
    vector<int> p;
    string s;
    while(getline(cin, s)) {
        p.push_back(s.size());
    }

    int m = *max_element(ALL(p));

    int sum = 0;
    for(int i = 0; i < p.size()-1; i++)
        sum += sqr(m - p[i]);
    cout << sum << endl;
}

