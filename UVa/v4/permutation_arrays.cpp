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


int main() {
    ios_base::sync_with_stdio(false);
    int t, x;
    string ln, s;

    cin >> t;
    cin.get();
    while(t--) {
        cin.get();
        getline(cin, ln);
        stringstream ss(ln);
        vector<int> p;
        vector<string> a, b;
        while(ss >> x) p.push_back(x-1);
        getline(cin, ln);
        stringstream ss2(ln);
        while(ss2 >> s) a.push_back(s);

        b.resize(a.size());

        for(int i = 0; i < p.size(); i++)
            b[p[i]] = a[i];
        for(int i = 0; i < p.size(); i++)
            cout << b[i] << endl;
        if(t) cout << endl;
    }
}

