#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b))? (a) : (b))

#define MAXBUFF (1<<25)
char buffer[MAXBUFF], *p = buffer+MAXBUFF;

char read_char() {
    if( p == buffer+MAXBUFF ) {
        fread( buffer, 1, MAXBUFF, stdin );
        p = buffer;
    }
    return *p++;
}

int read_signed_int() {
    char c;
    int ret, sign;
    while( !isdigit(c = read_char()) && c != '-' );
    sign = 1;
    if (c == '-') sign = -1, c = read_char();
    ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret * sign;
}

int read_unsigned_int() {
    char c;
    int ret;
    while( !isdigit(c = read_char()) );
    ret = c-'0';
    while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
    return ret;
}

void read_string(char str[]) {
    char c = read_char();
    int n = 0;

    while(isalpha(c)) {
        str[n++] = c;
        c = read_char();
    }
    str[n] = 0;
}

char name[510];

int main() {
    int t, n, k, ans, i, j, case_id;

    t = read_signed_int();

    for(case_id = 1; case_id <= t; case_id++) {
        n = read_signed_int();
        k = read_signed_int();
        read_string(name);

        ans = 0;

        for(i = 0; i < n; i++) {
            for(j = i-1; j >= max(0, i-k); j--) {
                if(name[i] == name[j]) {
                    ans++;
                    break;
                }
            }
        }

        printf("Case %d: %d\n", case_id, ans);
    }
    return 0;
}

