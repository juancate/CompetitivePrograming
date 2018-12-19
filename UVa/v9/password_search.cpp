#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#include <tr1/unordered_map>

#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    string s;

    while(cin >> n >> s) {
        std::tr1::unordered_map<string, int> cnt;
        for(int i = 0; i <= s.size()-n; i++) {
            cnt[s.substr(i, n)]++;
        }

        string ans;
        int best = 0;
        foreach(it, cnt) {
            if(it->second > best) {
                best = it->second;
                ans = it->first;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
