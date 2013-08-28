#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, b, h, w;

    while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF) {
        int best = int(1e9);

        for(int i = 0; i < h; i++) {
            int p;
            scanf("%d", &p);
            for(int j = 0; j < w; j++) {
                int c;
                scanf("%d", &c);
                if(c >= n) {
                    best = min(best, n * p);
                }
            }
        }
        if(best > b) puts("stay home");
        else printf("%d\n", best);
    }
}
