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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

bool is_prime(int q) {
    int p = 2;

    vector<int> fact;

    while(p <= q / p) {
        if(q % p == 0) {
            while(q % p == 0) {
                fact.push_back(p);
                q /= p;
            }
        }
        p++;
    }

    if(q > 1)
        fact.push_back(q);

    return (fact.size() == 0 || fact[0] == q);
}

int getcode(char c) {
    if(islower(c)) return c - 'a' + 1;
    return c - 'A' + 1 + 26;
}

char word[30];

int main() {
    while(gets(word)) {
        int n = strlen(word);

        int sum = 0;

        REP(i, 0, n)
            sum += getcode(word[i]);

        puts((is_prime(sum) || sum == 1)? "It is a prime word." : "It is not a prime word.");
    }
}

