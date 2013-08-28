#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl

using namespace std;

string st[][10] = { { ".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*" },
                    { "**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*." },
                    { "..", "..", "..", "..", "..", "..", "..", "..", "..", ".." } };

char s[3][300]; // 300 limit

int main() {
	while(true) {
		int D, n;
		scanf("%d\n", &D);
		if(D == 0) return 0;
		char ord;
		scanf("%c\n", &ord);
		memset(s, 0, sizeof(s));
		gets(s[0]);
		int len = strlen(s[0]);
		if(ord == 'S') {
			int j = 0;
			while(j < 3) {
				for(int i = 0; i < len; i++) {
					int num = s[0][i] - '0';
					if(i) printf(" ");
					printf("%s", st[j][num].c_str());
				}
				puts("");
				j++;
			}
		}
		else {
			gets(s[1]); gets(s[2]);
			for(int i = 0; i < strlen(s[0]); i += 3) { // for each num
				for(int j = 0; j < 10; j++)
                    if(s[0][i] == st[0][j][0] && s[0][i+1] == st[0][j][1]) {
					// search braille
                        if(s[1][i] == st[1][j][0] && s[1][i+1] == st[1][j][1]) {
                            printf("%c", (j+'0'));
                            break;
                        }
                    }
			}
			puts("");
		}
	}
}
