#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)

using namespace std;

string notes[3] = { " |\\",
                    " | ",
                    "x| " };

int row[7] = { 4, 3, 2, 1, 7, 6, 5 };

string line[11];

void create_line() {
    line[0]  = "|                        |                        |                        |                        |";
    line[1]  = "|------------------------|------------------------|------------------------|------------------------|";
    line[2]  = "|                        |                        |                        |                        |";
    line[3]  = "|------------------------|------------------------|------------------------|------------------------|";
    line[4]  = "|                        |                        |                        |                        |";
    line[5]  = "|------------------------|------------------------|------------------------|------------------------|";
    line[6]  = "|                        |                        |                        |                        |";
    line[7]  = "|------------------------|------------------------|------------------------|------------------------|";
    line[8]  = "|                        |                        |                        |                        |";
    line[9]  = "|------------------------|------------------------|------------------------|------------------------|";
    line[10] = "|                        |                        |                        |                        |";
}

void paint(int col, char note, bool alt = false) {
    int i, j, k, l;

    for(i = row[note - 'A'], k = 0; k < 3; i++, k++) {
        for(j = col, l = 0; l < 3; j++, l++) {
            if(notes[k][l] == ' ') continue;
            line[i][j] = notes[k][l];
        }
    }

    if(alt) line[i-1][col-1] = '#';
}

void print_line(bool first = false, bool last = false) {
    char f = ' ';
    if(first) f = '|';

    REP(i, 0, 11) {
        printf("%c%s", f, line[i].c_str());
        if(last) printf("|");
        printf("\n");
    }
}

int main() {
    int N;
    char note[10];
    while(scanf("%d", &N) && N != -1) {
        create_line();
        int cnt = 1, col = 2;
        bool first = true, last = false;
        REP(i, 0, N) {
            scanf("%s", note);
            paint(col, note[0], note[1] == '#');
            cnt++;
            col += 6;
            if(line[0][col-1] == '|') col++;

            if(cnt > 16) {
                if(i + 1 == N) last = true;
                print_line(first, last);
                if(first) first = false;
                create_line();
                cnt = 1;
                col = 2;
            }
        }
        if(!last) {
            print_line(first, true);
        }
        puts("");
    }
}

