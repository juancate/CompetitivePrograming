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

string num;

int n;
int64 d;

int64 convert(string a) {
    stringstream ss(a);
    int64 v; ss >> v;
    return v;
}

string tostr(int64 p) {
    stringstream ss;
    ss << p;
    return ss.str();
}

int count_nines(int64 p) {
    stringstream ss;
    ss << p;
    string a = ss.str();
    int cnt = 0;

    for(int i = a.size() - 1; i >= 0; i--) {
        if(a[i] == '9')
            cnt++;
        else
            break;
    }
    return cnt;
}

int len(int64 p) {
    stringstream ss;
    ss << p;
    return ss.str().size();
}

int64 find(string a) {
    int64 p = convert(a);

    num = tostr(p - d);

    string zeroes = "";

    REP(i, 0, 18 - num.size())
        zeroes.push_back('0');

    num = zeroes + num;

    int64 q = convert(num);

    int best = 0;

    for(int i = num.size() - 1; i >= 0; i--) {
        char prev = num[i];
        num[i] = '9';

        int64 curr = convert(num);

        if(curr >= p - d && curr <= p) {
            best = count_nines(curr);
            continue;
        }

        while(prev < '9') {
            num[i] = ++prev;
            curr = convert(num);

            if(curr > p) {
                num[i]--;
                break;
            }
        }
    }
    return convert(num);
}
int main() {
    ios_base::sync_with_stdio(false);
    string a;
    cin >> a >> d;
    n = a.size();
    cout << find(a) << endl;
}

