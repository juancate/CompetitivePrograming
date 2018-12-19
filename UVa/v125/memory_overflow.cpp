#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int case_id = 1; case_id <= t; case_id++) {
        int n, k;
        string name;

        cin >> n >> k >> name;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= max(i-k, 0); j--) {
                if(name[i] == name[j]) {
                    ans++;
                    break;
                }
            }
        }

        cout << "Case " << case_id << ": " << ans << endl;
    }
}
