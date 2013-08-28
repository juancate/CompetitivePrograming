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

const string word = "problem";

string tolow(const string& s) {
    string low;
    for(int i = 0; i < s.size(); i++)
        low.push_back(tolower(s[i]));
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    while(getline(cin, s)) {
        s = tolow(s);
        cout << ((s.find(word) != string::npos)? "yes" : "no") << endl;
    }
    return 0;
}

