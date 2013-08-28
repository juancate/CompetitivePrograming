#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.get();
    for(int case_id = 1; case_id <= t; case_id++) {
        string s;
        getline(cin, s);
        memset(cnt, 0, sizeof(cnt));
        int n = (int)s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(isalpha(s[i]))
                cnt[tolower(s[i]) - 'a']++;
        }
        sort(cnt, cnt+26);
        for(int i = 25, j = 26; i >= 0; i--, j--) {
            ans += cnt[i] * j;
        }

        cout << "Case #" << case_id << ": " << ans << endl;
    }
}
