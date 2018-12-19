#include <stdio.h>
#include <stdlib.h>

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

#define min(x,y) (x < y)? x : y

char s[10010];
int len;

int minExp() {
    int i = 0, j = 1, k = 0, x, y;

    while(i < len && j < len) {
    	x = i+k;
	    y = j+k;

    	if(x >= len) x -= len;
	    if(y >= len) y -= len;

        if(s[x] == s[y]) {
            k++;
            if(k == len) break;
        }
        else {
            if(s[x] > s[y]) {
                i = i+k+1;
                if(i <= j)
                    i = j+1;
            }
            else if(s[x] < s[y]) {
                j = j+k+1;
                if(j <= i)
                    j = i+1;
            }
            k = 0;
        }
    }

    return min(i, j);
}

int main() {
    int t = read_int();

    while(t--) {
    	len = 0;
        while((s[len] = read_char()) != '\n') len++;
        s[len] = 0;
        printf("%d\n", minExp() + 1);
    }
    return 0;
}
