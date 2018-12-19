#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1111

char seq[MAXN][MAXN];

void generate(int n) {
    int i, pos, cnt, sz, pos_temp;
    char current;

    for(i = 1; i < n; i++) {
        current = seq[i-1][0];
        pos = 0;
        cnt = 1;
        sz = strlen(seq[i-1]);
        pos_temp = 0;

        while(pos < sz && strlen(seq[i]) <= 1000) {
            pos++;
            if(seq[i-1][pos] == current) {
                cnt++;
            } else {
                seq[i][pos_temp++] = cnt + '0';
                seq[i][pos_temp++] = current;
                current = seq[i-1][pos];
                cnt = 1;
            }
        }
    }
}

int main() {
    int i, j;
    memset(seq, 0, sizeof(seq));
    while(~scanf("%s%d%d", seq[0], &i, &j) && (i|j) && seq[0][0] != '0') {
        generate(i);
        printf("%c\n", seq[i-1][j-1]);
        memset(seq, 0, sizeof(seq));
    }
    return 0;
}

