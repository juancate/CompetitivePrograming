#include <cstdio>
#include <cstdlib>
#include <cstring>

// Implementation

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, R;
		char S[30];
		scanf("%d %d %s", &N, &R, S);
		int M = strlen(S);
		printf("%d ", N);
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < R; j++) printf("%c", S[i]);
		}
		printf("\n");
	}
}
