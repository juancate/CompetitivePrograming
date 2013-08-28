#include <cstdio>

#define max(x,y) (((x) > (y))? (x) : (y))

int main() {
    int t, n, best, i, case_id, x;
    scanf("%d", &t);
    t++;
    for(case_id = 1; case_id < t; case_id++) {
        scanf("%d", &n);
        best = 1;
        for(i = 0; i < n; i++) {
            scanf("%d", &x);
            best = max(best, x);
        }
        printf("Case %d: %d\n", case_id, best);
    }

    return 0;
}
