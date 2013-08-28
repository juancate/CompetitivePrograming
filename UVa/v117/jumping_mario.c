#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int64 read_int64() {
    char c;
    int64 r;

    while( !isdigit( c = read_char() ) );

    r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}

int main() {
    int t, n, current, next, i, hi, lo, case_id;

    t = read_int();
    for(case_id = 1; case_id <= t; case_id++) {
        n = read_int();
        current = read_int();

        hi = lo = 0;

        for(i = 1; i < n; i++) {
            next = read_int();
            if(next > current)
                hi++;
            else if(next < current)
                lo++;
            current = next;
        }
        printf("Case %d: %d %d\n", case_id, hi, lo);
    }

    return 0;
}

