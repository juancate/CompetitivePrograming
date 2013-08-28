#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = (int)(1e9);
const int MAXN = 100000;

int L, N, limit;
int words[MAXN];
char name[100];

bool can(int width) {
    int line_cnt = 1;
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        if(cnt + words[i] <= width) {
            cnt += words[i];
            if(cnt < width) cnt++;
        } else {
            if(words[i] > width) return false;
            cnt = words[i];
            if(cnt < width) cnt++;
            line_cnt++;
        }
    }
    return (line_cnt <= L);
}

int search() {
    int lo = 0, hi = limit;

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(can(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main() {
    while(scanf("%d%d", &L, &N) && L!=-1 && N!=-1) {
        limit = 0;
        for(int i = 0; i < N; i++) {
            scanf("%s", name);
            words[i] = strlen(name);
            limit += words[i] + 1;
        }

        printf("%d\n", search());
    }
}

