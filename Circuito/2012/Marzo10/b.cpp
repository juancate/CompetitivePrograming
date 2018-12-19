#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>

#define D(x) cerr << #x << " = " << (x) << endl

using namespace std;

// Adhoc - Implementation

int n, m;

int main() {
	int casos;
	scanf("%d", &casos);
	while(casos--) {
		int id;
		scanf("%d %d %d", &id, &n, &m);
		int ans = 1;
		if(m > n or n < 0 or m < 0) ans = 0;
		else if(n == m or m == 0) ans = 1;
		else ans += m*(n - m);
    printf("%d %d\n", id, ans);
	}
}

