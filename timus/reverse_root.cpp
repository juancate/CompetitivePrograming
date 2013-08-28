#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> r;
    long long n;
    while(~scanf("%lld", &n))
        r.push_back(sqrt((double)n));
    for(int i = r.size()-1; i >= 0; i--)
        printf("%.4lf\n", r[i]);
    return 0;
}
