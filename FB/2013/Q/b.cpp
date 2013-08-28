#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solve(string s) {
    stack<char> stk;
    int n = (int)s.size();
    for(int i = 0; i < n; i++) {
        if(isalpha(s[i]) || s[i] == ' ') continue;
        if(s[i] == ':' || s[i] == '(') stk.push(s[i]);
        if(s[i] == ')') {
            if(stk.empty()) return false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.get();
    for(int case_id = 1; case_id <= t; case_id++) {
        string s;
        cin >> s;
        cout << (solve(s)? "YES" : "NO") << endl;
    }
    return 0;
}
