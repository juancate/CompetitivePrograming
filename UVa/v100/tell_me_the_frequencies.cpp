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
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int c[128];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    int cnt = 0;

    while(getline(cin, s)) {
        memset(c, 0, sizeof c);
        foreach(ch, s) {
            c[*ch]++;
        }

        if(cnt++) cout << endl;
        vector< pair<int, int> > ans;

        for(int i = 0; i < 128; i++) {
            if(c[i])
                ans.push_back(make_pair(i, c[i]));
        }
        sort(ans.begin(), ans.end(), cmp);

        foreach(it, ans) {
            cout << it->first << ' ' << it->second << endl;
        }
    }
    return 0;
}

