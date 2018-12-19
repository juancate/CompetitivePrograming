#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        printf("%d\n", (z * (2*x - y)) / (x + y));
    }
    return 0;
}
