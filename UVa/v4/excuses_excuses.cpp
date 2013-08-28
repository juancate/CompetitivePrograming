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

set<string> dict;
int rank[20], k, e;
string sent[20];

string clear_string(const string& s) {
    string r;

    foreach(ch, s) {
        if(isalpha(*ch)) r.push_back(tolower(*ch));
        else r.push_back(' ');
    }

    return r;
}

int excuse_value(const string& s) {
    int r = 0;

    stringstream ss(clear_string(s));
    string w;

    while(ss >> w) {
        if(dict.count(w)) r++;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);

    int case_id = 0;

    while(cin >> k >> e) {
        dict.clear();
        string s;
        for(int i = 0; i < k; i++) {
            cin >> s;
            dict.insert(s);
        }
        cin.get();
        for(int i = 0; i < e; i++) {
            getline(cin, sent[i]);
            rank[i] = excuse_value(sent[i]);
        }

        int best = *max_element(rank, rank+e);

        cout << "Excuse Set #" << ++case_id << endl;
        for(int i = 0; i < e; i++)
            if(rank[i] == best)
                cout << sent[i] << endl;
        cout << endl;
    }

    return 0;
}

