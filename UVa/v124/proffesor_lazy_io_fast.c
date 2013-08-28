#include <stdio.h>
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
    int a, b;
    int64 n;

    while(true) {
        a = read_int(); b = read_int();
        n = read_int64();

        if(a == 0) break;

        n %= 5;

        if(n == 0) printf("%d\n", a);
        else if(n == 1) printf("%d\n", b);
        else if(n == 2) printf("%lld\n", (1LL + b) / a);
        else if(n == 3) printf("%lld\n", (1LL + a + b) / ((int64)a * b));
        else if(n == 4) printf("%lld\n", (1LL + a) / b);
    }
}

