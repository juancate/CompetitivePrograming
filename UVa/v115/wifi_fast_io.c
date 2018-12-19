#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Slow!
*/

#define SIZE (1 << 19)
typedef long long int64;

char buff[SIZE], *p = buff + SIZE;

char read_char() {
    if( p == buff + SIZE ) {
        fread( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
}

int read_int() {
    char c;
    int r;

    while( !isdigit( c = read_char() ) );

    r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}

int n, m;
int h[111111];

int check(int dist) {
    int checkpoints, point, i, diff;

    checkpoints = 1;
    point = h[0] + dist;
    for(i = 1; i < m; i++) {
        diff = fabs(h[i] - point);
        if(diff > dist) {
            point = h[i] + dist;
            checkpoints++;
        }
    }
    return (checkpoints <= n);
}

int binarySearch() {
    int lo, hi, mid;

    lo = 0; hi = h[m-1];

    while(lo < hi) {
        mid = lo + (hi - lo) / 2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }

    return lo;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int i, t;
    t = read_int();

    while(t--) {
        n = read_int(); m = read_int();

        for(i = 0; i < m; i++)
            h[i] = read_int() * 10;

        qsort(h, m, sizeof(int), cmp);

        printf("%.1lf\n", binarySearch() / 10.);
    }
    return 0;
}
