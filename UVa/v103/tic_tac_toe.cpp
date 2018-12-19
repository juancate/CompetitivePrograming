#include <cstdio>

char board[3][4];

bool win(char c) {
    for(int i = 0; i < 3; i++) {
        bool w = true;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != c) {
                w = false;
                break;
            }
        }
        if(w) return true;
    }

    for(int i = 0; i < 3; i++) {
        bool w = true;
        for(int j = 0; j < 3; j++) {
            if(board[j][i] != c) {
                w = false;
                break;
            }
        }
        if(w) return true;
    }
    bool w = true;
    for(int i = 0; i < 3; i++) {
        if(board[i][i] != c) {
            w = false;
            break;
        }
    }
    if(w) return true;
    w = true;
    for(int i = 0; i < 3; i++) {
        if(board[i][2-i] != c) {
            w = false;
            break;
        }
    }
    if(w) return true;
    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int x = 0, o = 0;
        for(int i = 0; i < 3; i++) {
            scanf("%s", board[i]);
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 'X') x++;
                else if(board[i][j] == 'O') o++;
            }
        }

        if(win('X') && win('O')) puts("no");
        else if(win('O') && x != o) puts("no");
        else if(win('X') && x == o) puts("no");
        else if(x == o || x-1 == o) puts("yes");
        else puts("no");
    }

    return 0;
}
