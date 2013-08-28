#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int s, t;
    cin >> s >> t;
    s--, t--;

    int best = int(1e9);
    int sum = 0;
    for(int i = s; i != t; i = (i+1) % n) {
        sum += v[i];
    }
    best = min(best, sum);
    sum = 0;
    for(int i = (s-1+n) % n; ; i = (i-1+n) % n) {
        sum += v[i];
        if(i == t) break;
    }
    best = min(best, sum);
    cout << best << endl;

    return 0;
}
