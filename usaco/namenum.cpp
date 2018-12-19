/*
ID: jcamarg1
PROG: namenum
LANG: C++
*/

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
#include <fstream>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

char keys[10][3];

int n;
string code;
vector<string> valid;
set<string> dict;

ifstream in("namenum.in");
ofstream out("namenum.out");

void redirect() {
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
}

void load_dict() {
    ifstream f("dict.txt");
    string s;
    while(f >> s) {
        dict.insert(s);
    }
    f.close();
}

void load_keys() {
    char ch = 'A';
    for(int i = 2; i < 10; i++) {
        for(int j = 0; j < 3; j++) {
            if(ch == 'Q') ch++;
            keys[i][j] = ch++;
        }
    }
}

void backtracking(int i, string s) {
    if(i == n) {
        if(dict.count(s)) {
            valid.push_back(s);
        }
        return;
    }

    for(int j = 0; j < 3; j++) {
        int id = code[i] - '0';
        s.push_back(keys[id][j]);
        backtracking(i+1, s);
        s.erase(s.end()-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    load_dict();
    redirect();
    load_keys();

    cin >> code;

    n = (int)code.size();
    backtracking(0, "");

    if(valid.empty()) cout << "NONE" << endl;
    else {
        FOREACH(v, valid)
            cout << *v << endl;
    }

    in.close();
    out.close();
}

