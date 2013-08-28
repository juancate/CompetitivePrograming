#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	char cmd[100];
	int T, k, sum = 0;
	scanf("%d\n", &T);
	while(T--) {
		scanf("%s", cmd);
		if(cmd[0] == 'd') {
			scanf("%d\n", &k);
			sum += k;
		} else {
			scanf("\n");
			printf("%d\n", sum);
		}
	}
}
