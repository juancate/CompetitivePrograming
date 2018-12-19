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

const int maxn = 100;

stack<int> carrier;
queue<int> b[maxn];

bool finished(int n) {
    if(carrier.size() > 0) return false;
    for(int i = 0; i < n; i++)
        if(b[i].size() > 0)
            return false;
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, s, q;
        scanf("%d%d%d", &n, &s, &q);

        for(int i = 0; i < n; i++) {
            int Qi, k;
            scanf("%d", &Qi);
            while(Qi--) {
                scanf("%d", &k);
                b[i].push(k-1);
            }
        }

        int ans = 0;
        int curr_station = 0;

        while(true) { // stops when all B are empty and carrier
            // unload to destination or to b
            while(!carrier.empty()) {
                if(carrier.top() == curr_station) {
                    carrier.pop();
                    ans++;
                } else if(b[curr_station].size() < q) {
                    b[curr_station].push(carrier.top());
                    carrier.pop();
                    ans++;
                } else {
                    break;
                }
            }

            // load to carrier
            while(!b[curr_station].empty() && carrier.size() < s) {
                carrier.push(b[curr_station].front());
                b[curr_station].pop();
                ans++;
            }

            curr_station = (curr_station + 1) % n;
            if(finished(n)) break;
            ans += 2;
        }

        printf("%d\n", ans);
    }

    return 0;
}

