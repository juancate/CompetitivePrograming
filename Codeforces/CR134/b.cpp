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

int n, m, max_a;
vector<int> A;

int find_min() {
    int money = 0, pass = n;

    priority_queue<int> Q;

    REP(i, 0, m) Q.push(-A[i]);

    while(!Q.empty() && pass > 0) {
        int c = -Q.top(); Q.pop();
        money += c;
        c--;
        pass--;
        if(c > 0)
            Q.push(-c);
    }

    return money;
}

int find_max() {
    int money = 0, pass = n;

    priority_queue<int> Q;

    REP(i, 0, m) Q.push(A[i]);

    while(!Q.empty() && pass > 0) {
        int c = Q.top(); Q.pop();
        money += c;
        c--;
        pass--;
        if(c > 0)
            Q.push(c);
    }

    return money;
}

int main() {
    ios_base::sync_with_stdio(false);

    max_a = 0;
    cin >> n >> m;
    A.resize(m);
    REP(i, 0, m) cin >> A[i], max_a = max(max_a, A[i]);

    int min = find_min();
    int max = find_max();

    cout << max << ' ' << min << endl;
}

