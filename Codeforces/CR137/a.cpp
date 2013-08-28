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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    REP(i, 0, n) cin >> nums[i];

    bool equals = true;

    for(int i = 1; i < n && equals; i++) {
        if(nums[i] != nums[i-1])
            equals = false;
    }

    if(equals) {
        cout << 0 << endl;
        return 0;
    }

    int x = nums[k-1];

    equals = true;

    for(int i = k-1; i < n && equals; i++) {
        if(nums[i] != x)
            equals = false;
    }

    if(!equals) {
        cout << -1 << endl;
    }
    else {
        while(nums[k-1] == x)
            k--;

        cout << k << endl;
    }
}

