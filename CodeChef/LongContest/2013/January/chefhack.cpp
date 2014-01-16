#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

namespace IO {
    #define MAXBUFF (1<<18)
    char buffer[MAXBUFF], *p = buffer+MAXBUFF;

    inline char read_char() {
        if( p == buffer+MAXBUFF ) {
            fread( buffer, 1, MAXBUFF, stdin );
            p = buffer;
        }
        return *p++;
    }

    inline int read_signed_int() {
        char c;
        while( !isdigit(c = read_char()) and c != '-' );
        int sign = 1;
        if (c == '-') sign = -1, c = read_char();
        int ret = c-'0';
        while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
        return ret * sign;
    }

    inline int read_unsigned_int() {
        char c;
        while( !isdigit(c = read_char()) );
        int ret = c-'0';
        while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
        return ret;
    }
}
using namespace IO;

const int INF = (int)(1e9);

const int maxn = 360;

int n, board[maxn][maxn];
bool visited[maxn][maxn];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

long long sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(long long upper) {
    sieve_size = upper + 1;
    bs.set();
    bs[0] = bs[1] = 0;

    for(long long i = 2; i <= sieve_size; i++) if(bs[i]) {
        for(long long j = i * i; j  <= sieve_size; j += i)
            bs[j] = 0;
        primes.push_back((int)i);
    }
}

inline bool is_prime(int x) {
    if(x <= sieve_size) return bs[x];

    for(int i = 0; i < (int)primes.size(); i++)
        if(x % primes[i] == 0) return false;
    return true;
}

inline bool valid(int nr, int nc) {
    return (nr >= 0 && nr < n && nc >= 0 && nc < n);
}

// ord: 0 even, 1 odd
void dfs(int r, int c, int ord) {
    if(visited[r][c]) return;
    if(is_prime(board[r][c])) return;

    visited[r][c] = true;

    for(int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(valid(nr, nc) && !visited[nr][nc]) {
            if((board[nr][nc] & 1) == ord && !is_prime(board[nr][nc]))
                dfs(nr, nc, ord);
        }
    }
}

int main() {
    int t = read_signed_int();
    //scanf("%d", &t);

    // precalculate primes
    sieve(10000000);

    while(t--) {
        //scanf("%d", &n);
        n = read_signed_int();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                //scanf("%d", &board[i][j]);
                board[i][j] = read_signed_int();
                visited[i][j] = false;
            }
        }

        long long cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) continue;

                if(is_prime(board[i][j])) {
                    visited[i][j] = true;

                    int index = int(lower_bound(ALL(primes), board[i][j]) - primes.begin());
                    cnt += index;
                }
                else if(!(board[i][j] & 1)) {
                    cnt += board[i][j] >> 1;
                    dfs(i, j, 0);
                }
                else if(board[i][j] & 1) {
                    cnt += ((board[i][j] + 1) >> 1) + 1;
                    dfs(i, j, 1);
                }
            }
        }

        printf("%lld\n", cnt);
    }
    return 0;
}

