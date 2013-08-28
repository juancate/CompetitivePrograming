#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cmath>

#include <unistd.h>

class INPUT {
    static const int BUFSIZE = 1<<16;
    static char buffer[];
    char *bufpos;
    char *bufend;
    void grabBuffer();
public:
    INPUT() { grabBuffer(); }
    bool eof() { return bufend==buffer; }
    char nextChar() { return *bufpos; }
    inline char readChar();
    inline void skipWS();
    inline unsigned readUnsigned();
    inline int readInt();
    inline double readDouble();
};

char INPUT::buffer[INPUT::BUFSIZE];

void INPUT::grabBuffer() {
    bufpos = buffer;
    bufend = buffer + read(0, buffer, BUFSIZE);
}

char INPUT::readChar() {
    char res = *bufpos++;
    if(bufpos==bufend) grabBuffer();
    return res;
}

inline bool myisspace(char c) { return c<=' '; }

void INPUT::skipWS() {
    while(!eof() && myisspace(nextChar())) readChar();
}

unsigned INPUT::readUnsigned() {
    skipWS();
    unsigned res = 0;
    while(!eof() && isdigit(nextChar())) {
        res = 10u * res + (readChar()-'0');
    }
    return res;
}

int INPUT::readInt() {
    skipWS();
    bool neg = false;
    if(!eof() && nextChar()=='-') { neg=true; readChar(); }
    int res = static_cast<int>(readUnsigned());
    if(neg) res = -res;
    return res;
}

double INPUT::readDouble() {
    skipWS();
    double res = 0.0;
    int sign = 1;

    if(nextChar() == '-') {
        sign = -1;
        readChar();
    }

    while(!eof() && isdigit(nextChar())) {
        res *= 10;
        res += (readChar() - '0');
    }

    if(nextChar() == '.') {
        readChar();
        double m = 1;
        while(!eof() && isdigit(nextChar())) {
            m /= 10;
            res += (readChar() - '0') * m;
        }
    }

    return res * sign;
}

using namespace std;

const int MAXN = 111;

int n;
int GA[MAXN][MAXN], GB[MAXN][MAXN];
double d[MAXN];
INPUT in;

#define mp make_pair

int dijkstra(int source, int sink, double a) {
    for(int i = 0; i < n; i++) d[i] = 1e50;

    d[source] = 0;
    priority_queue< pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > > Q;
    Q.push( mp(0.0, source) );
    while(!Q.empty()) {
        int v = Q.top().second;
        double cost = Q.top().first;
        Q.pop();

        if(cost > d[v]) continue;
        if(v == sink) return floor(cost);

        for(int u = 0; u < n; u++) {
            if(GA[v][u] == -1 && GB[v][u] == -1) continue;
            double diff;
            if(GA[v][u] != -1 && GB[v][u] != -1) {
                diff = a * GA[v][u] + (1. - a) * GB[v][u];
            } else {
                diff = max(GA[u][v], GB[v][u]);
            }
            if(diff + cost < d[u]) {
                d[u] = diff + cost;
                Q.push(mp(diff + cost, u));
            }
        }
    }
    return -1;
}

int main() {
    int ma, mb, k;
    while(true) {
        n = in.readInt(), ma = in.readInt(), mb = in.readInt(), k = in.readInt();

    	if(n == -1 && ma == -1 && mb == -1 && k == -1)
    	    break;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                GA[i][j] = GB[i][j] = -1;

    	for(int i = 0; i < ma; i++) {
    	    int a, b, c;
            a = in.readInt(), b = in.readInt(), c = in.readInt();
    	    GA[a][b] = GA[b][a] = c;
    	}
    	for(int i = 0; i < mb; i++) {
    	    int a, b, c;
            a = in.readInt(), b = in.readInt(), c = in.readInt();
            GB[a][b] = GB[b][a] = c;
    	}
    	for(int i = 0; i < k; i++) {
    	    double a = in.readDouble();
    	    printf("%d\n", dijkstra(0, n-1, a));
    	}
    }
}
