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

string tostr(int64 x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

int64 reverse(int64 x) {
    string s = tostr(x);
    reverse(s.begin(), s.end());
    return atoll(s.c_str());
}

bool is_palindrome(int64 x) {
    string s = tostr(x);
    int i = 0, j = s.size()-1;
    while(i < j) {
        if(s[i++] != s[j--])
            return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int64 x;
        scanf("%lld", &x);

        int it = 0;

        while(true) {
            if(is_palindrome(x))
                break;
            x = x + reverse(x);
            it++;
        }
        printf("%d %lld\n", it, x);
    }
    return 0;
}

