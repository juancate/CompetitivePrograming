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

// Problem: 551 - Nesting a Bunch of Brackets
// Algorithm: Stack

#define mp make_pair

string inverse(const string& a) {
    if(a == "*)") return "(*";
    if(a == ">") return "<";
    if(a == "}") return "{";
    if(a == "]") return "[";
    return "(";
}

vector<string> split(const string& a) {
    int pos = 1;
    int n = (int)a.size();
    vector<string> ret;

    for(int i = 0; i < n; i++) {
        string current;
        current.push_back(a[i]);

        if(a[i] == '(') {
            if(i+1 < n && a[i+1] == '*') {
                i++;
                current.push_back(a[i]);
            }
        } else if(a[i] == '*') {
            if(i+1 < n && a[i+1] == ')') {
                i++;
                current.push_back(a[i]);
            }
        }

        ret.push_back(current);
    }

    return ret;
}

int main() {
    set<string> tokens;
    tokens.insert("("); tokens.insert(")");
    tokens.insert("["); tokens.insert("]");
    tokens.insert("{"); tokens.insert("}");
    tokens.insert("<"); tokens.insert(">");
    tokens.insert("(*"); tokens.insert("*)");

    set<string> ending_tokens;
    ending_tokens.insert(")"); ending_tokens.insert("]");
    ending_tokens.insert("}"); ending_tokens.insert(">");
    ending_tokens.insert("*)");

    ios_base::sync_with_stdio(false);

    string line;

    while(cin >> line) {
        vector<string> v = split(line);
        int n = (int)v.size();

        stack< pair<string, int> > S;

        int error_element = -1;

        for(int i = 0; i < n && error_element < 0; i++) {
            if(!S.empty()) {
                if(tokens.count(v[i])) {
                    if(ending_tokens.count(v[i])) {
                        if(S.top().first == inverse(v[i])) {
                            S.pop();
                        }
                        else {
                            error_element = i;
                        }
                    }
                    else {
                        S.push( mp(v[i], i) );
                    }
                }
            }
            else {
                if(ending_tokens.count(v[i]))
                    error_element = i;
                else if(tokens.count(v[i]))
                    S.push( mp(v[i], i) );
            }
        }

        if(error_element < 0 && !S.empty())
            error_element = n;

        if(error_element >= 0)
            cout << "NO " << (error_element+1) << endl;
        else
            cout << "YES" << endl;
    }
}

