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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    sort(ALL(s));
    reverse(ALL(s));

    string ans = s.substr(0, 1);
    int i = 1;

    while(i <= s.size()) {
        string pal = s.substr(0, i);
        reverse(ALL(pal));
        if(s.substr(0, i) != pal) break;
        if(s.substr(0, i) > ans) ans = s.substr(0, i);
        i++;
    }

    cout << ans << endl;
}

