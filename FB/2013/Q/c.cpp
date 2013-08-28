#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

void print(const vector<long long>& m) {
    cerr << "[";
    for(int i = 0; i < m.size(); i++)
        cerr << m[i] << ", ";
    cerr << "]\n";
}

int main() {
    int t;
    scanf("%d", &t);
    for(int case_id = 1; case_id <= t; case_id++) {
        long long n, k, a, b, c, r;
        scanf("%lld%lld %lld%lld%lld%lld", &n, &k, &a, &b, &c, &r);
        vector<long long> m(k<<1, 0);
        //cerr << "[ ";
        m[0] = a;
        //cerr << m[0] << ", ";
        used[a] = true;
        for(int i = 1; i < k; i++) {
            m[i] = (b * m[i-1] + c) % r;
        }
        //cerr << "]" << endl;
        for(int i = k; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                bool ok = true;
                for(int l = i-k; l < i; l++) {
                    if(m[l] == j) {
                        ok = false; break;
                    }
                }
                if(ok) {
                    m[i] = j; break;
                }
            }
        }
        print(m);
        int ans = 0;
        //while(used[ans]) ans++;
        printf("Case #%d: %lld\n", case_id, m[n-1]);
    }
    return 0;
}
