#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d\n", &T);
	for(int id = 1; id <= T; id++) {
		int n;
		scanf("%d\n", &n);
		char field[n+1];
		bool visited[n];
		gets(field);
		memset(visited, false, sizeof(visited));
		
		int ans = 0;

		for(int i = 1; i < n; i++) {
			if(visited[i]) continue;
			if(field[i] == '#' && field[i-1] == '.' && !visited[i-1]) {
				ans++;
				visited[i-1] = true;
				field[i] = 's';
				if(i+1 < n && !visited[i+1]) {
					visited[i+1] = true;
				}
			} else if(field[i] == '.' && field[i-1] == '.' &&!visited[i-1]) {
				ans++;
				visited[i-1] = visited[i] = true;
				field[i] = 's';
			} else if(field[i-1] == 's') {
				visited[i] = true;
			}
		}
		if(!visited[n-1] && field[n-1] == '.') ans++;
		printf("Case %d: %d\n", id, ans);
	}
}
