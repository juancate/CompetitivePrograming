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

int main() {
    ios_base::sync_with_stdio(false);
    string a;
    cin >> a;
    int pos;
    while((pos = a.find("WUB")) != string::npos) {
        a.replace(pos, 3, " ");
    }
    string ans;
    int i, j;

    for(i = 0; i < a.size(); i++) {
        int spaces = 0;
        while(a[i] == ' ') i++, spaces++;
        if(spaces > 0) ans.push_back(' '), i--;
        else ans.push_back(a[i]);
    }

    for(i = 0; i < ans.size(); i++)
        if(ans[i] != ' ') break;

    for(j = ans.size()-1; j >= 0; j--)
        if(ans[j] != ' ') break;

    ans = ans.substr(i, j-i+1);

    cout << ans << endl;
}

