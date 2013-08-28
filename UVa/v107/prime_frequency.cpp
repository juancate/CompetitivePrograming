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

long long sieve_size;
bitset<2010> bs;
vector<int> primes;

void sieve(long long upper) {
    sieve_size = upper + 1;
    bs.set();
    bs[0] = bs[1] = 0;

    for(long long i = 2; i <= sieve_size; i++) if(bs[i]) {
        for(long long j = i * i; j  <= sieve_size; j += i)
            bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline bool is_prime(int x) {
    if(x <= sieve_size) return bs[x];

    for(int i = 0; i < (int)primes.size(); i++)
        if(x % primes[i] == 0) return false;
    return true;
}

int cnt[256];

string solve(char start, char end) {
    string r = "";

    for(char i = start; i <= end; i++)
        if(is_prime(cnt[i]))
            r.push_back(i);

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);

    sieve(2001);

    int t;
    cin >> t;

    for(int case_id = 1; case_id <= t; case_id++) {
        string s;
        cin >> s;

        memset(cnt, 0, sizeof cnt);

        foreach(ch, s) {
            cnt[*ch]++;
        }

        string ans = solve('0', '9') + solve('A', 'Z') + solve('a', 'z');
        if(ans.empty()) ans = "empty";
        cout << "Case " << case_id << ": " << ans << endl;
    }
}

