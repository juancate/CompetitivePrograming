#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int x = n / 3;
        int y = m / 3;
        if(n - 3*x > 2) x++;
        if(m - 3*y > 2) y++;

        printf("%d\n", x*y);
    }
    return 0;
}
