#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXBUFF (1<<24)
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
    int sign, ret;
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

#define LSOne(S) (S & (-S))

int n, t[200010];

void ft_create(int n) {
    n++;
    memset(t, 0, n * sizeof(int));
}

int _ft_rsq(int b) {
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += t[b];
    return sum;
}

int ft_rsq(int a, int b) {
    return _ft_rsq(b) - (a == 1? 0 : _ft_rsq(a-1));
}

void ft_adjust(int k, int v) {
    for(; k <= n; k += LSOne(k)) t[k] += v;
}

char ans_buffer[600000010];

int main() {
    char op;
    int case_id = 0, written = 0, i, j, x;

    while((n = read_unsigned_int())) {
        ft_create(n);

        for(i = 1; i <= n; i++) {
            x = read_unsigned_int();
            ft_adjust(i, x - ft_rsq(i, i));
        }

        if(case_id)
            written += sprintf(ans_buffer + written, "\n");

        written += sprintf(ans_buffer + written, "Case %d:\n", ++case_id);

        while(true) {
            op = read_char();
            if(op == 'E') break;
            i = read_unsigned_int();
            j = read_unsigned_int();

            if(op == 'S')
                ft_adjust(i, j - ft_rsq(i, i));
            else {
                written += sprintf(ans_buffer + written, "%d\n", ft_rsq(i, j));
            }
        }
    }
    printf(ans_buffer);
    return 0;
}

