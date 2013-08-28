#include <stdio.h>

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

int main() {
    int a, b, c, d, e, ans;

    while((a = read_int())) {
        b = read_int(); c = read_int();
        d = read_int(); e = read_int();
        printf("%d\n", a*b*c*d*d*e*e);
    }
}

