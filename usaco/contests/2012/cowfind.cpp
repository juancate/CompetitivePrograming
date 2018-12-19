#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <fstream>
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


int main() {
    ifstream in("cowfind.in");
    ofstream out("cowfind.out");

    ios_base::sync_with_stdio(false);

    string line;
    in >> line;

    int n = (int)line.size();

    vector<int> rparent(n, 0), dp(n, 0);

    for(int i = 1; i < n; i++) {
        if(line[i] == '(' && line[i] == line[i-1])
            rparent[i] = rparent[i-1] + 1;
        else
            rparent[i] = rparent[i-1];
    }

    for(int i = 1; i < n; i++) {
        if(line[i] == ')' && line[i] == line[i-1])
            dp[i] = rparent[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += dp[i];

    out << ans << '\n';

    in.close();
    out.close();
}

