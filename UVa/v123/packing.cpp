#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int t, w, h, l;

int main() {
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		scanf("%d %d %d", &l, &w, &h);
		printf("Case %d: %s\n", i, (l > 20 || w > 20 || h > 20)? "bad" : "good");
	}
}
