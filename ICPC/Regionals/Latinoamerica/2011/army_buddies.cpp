#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, q, L, R, ini, fin;

int main() {
    while(true) {
        scanf("%d %d", &n, &q);
        if((n|q) == 0)
            break;
        int soldiers[n+2];

        memset(soldiers, -1, sizeof(soldiers));

        for(int i = 0; i < q; i++) {
            scanf("%d %d", &L, &R);

            if(soldiers[L-1] == -1)
                ini = L;
            else
                ini = soldiers[L-1];

            if(soldiers[R+1] == -1)
                fin = R;
            else
                fin = soldiers[R+1];

            soldiers[L] = fin;
            soldiers[R] = ini;
            soldiers[ini] = fin;
            soldiers[fin] = ini;

            if(soldiers[fin]-1 == 0 || L-1 == 0)
                printf("* ");
            else
                printf("%d ",soldiers[fin]-1);

            if(soldiers[ini]+1 == n+1 || R+1 == n+1)
                printf("*\n");
            else
                printf("%d\n", soldiers[ini]+1);
        }
        puts("-");
    }
}
