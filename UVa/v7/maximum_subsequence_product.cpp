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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 111;

int data[MAXN];
int64 prod[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        int n = 0, x;
        prod[0] = 1; data[0] = 1;
        while(ss >> x) {
            if(x == -999999) break;
            prod[n+1] = prod[n] * x;
            data[n+1] = x;
            n++;
        }

        int64 max_prod = -INFLL;

        for(int i = 1; i <= n; i++) {
            int64 current_prod = 1;
            for(int j = 0; j < i; j++) {
                if(prod[j] == 0) current_prod = data[i];
                else current_prod = prod[i] / prod[j];
                max_prod = max(max_prod, current_prod);
            }
        }

        cout << max_prod << endl;
    }
}

