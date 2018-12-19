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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int find(string s) {
    int max = s.size() - 1;
    for (int i = s.size() - 2; i >= 0; i--)
        if (s[i] > s[max]) max = i;
    return max;
}

string remove(string s, char x, int start) {
    string ret;
    for (int i = start; i >= 0; i--) {
        if (s[i] == x) ret += s[i];
    }
    return ret;
}

string solve(string s) {
    if(s.size() == 0) return "";

    int x = find(s);
    string ret = remove(s, s[x], x) + solve(s.substr(x + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s, ans;
    cin >> s;
    cout << solve(s) << endl;
}

