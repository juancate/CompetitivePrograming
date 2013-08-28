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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
    return ( os << "(" << z.first << ", " << z.second << ",)" );
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const vector<T>& z){
    os << "[ ";
    REP(i,0,z.size())os << z[i] << ", " ;
    return ( os << "]" << endl);
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const set<T>& z){
    os << "set( ";
    FOREACH(p,z)os << (*p) << ", " ;
    return ( os << ")" << endl);
}
template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
    os << "{ ";
    FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
    return ( os << "}" << endl);
}

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

class OUTPUT {
    static const int BUFSIZE = 1<<16;
    static char buffer[];
    char *bufpos;
    char *BUFLIMIT;
public:
    void flushBuffer();
    OUTPUT():bufpos(buffer),BUFLIMIT(buffer+BUFSIZE-100) {}
    ~OUTPUT() { flushBuffer(); }
    inline void operator()(char c);
    inline void operator()(unsigned x);
    inline void operator()(int x);
    inline void operator()(const char*s);
    void operator()(const string&s) { operator()(s.c_str()); }
    template<class A,class B>
    void operator()(const A& a,const B& b) {
        operator()(a); operator()(b);
    }
    template<class A,class B,class C>
    void operator()(const A& a,const B& b,const C&c) {
        operator()(a); operator()(b); operator()(c);
    }
    template<class A,class B,class C,class D>
    void operator()(const A& a,const B& b,const C&c,const D&d) {
        operator()(a); operator()(b); operator()(c); operator()(d);
    }
    template<class A,class B,class C,class D,class E>
    void operator()(const A& a,const B& b,const C&c,const D&d,const E&e) {
        operator()(a); operator()(b); operator()(c); operator()(d); operator()(e);
    }
    template<class A,class B,class C,class D,class E,class F>
    void operator()(const A& a,const B& b,const C&c,const D&d,const E&e,const F&f) {
        operator()(a); operator()(b); operator()(c); operator()(d); operator()(e); operator()(f);
    }
};

char OUTPUT::buffer[OUTPUT::BUFSIZE];

void OUTPUT::flushBuffer() {
    char *p = buffer;
    while(p < bufpos) {
        p += write(1, p, bufpos-p);
    }
    bufpos = buffer;
}

void OUTPUT::operator()(char c) {
    *bufpos = c;
    ++bufpos;
    if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(unsigned x) {
    char *old = bufpos;
    do {
        *bufpos = char('0' + x % 10u);
        x /= 10u;
        ++bufpos;
    } while(x);
    reverse(old, bufpos);
    if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(int x) {
    if(x<0) { operator()('-'); x = -x; }
    operator()(static_cast<unsigned>(x));
}

void OUTPUT::operator()(const char*s) {
    while(*s) operator()(*s++);
}


typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;


int main() {
    INPUT in;
    OUTPUT out;
    int a, b, ans;
    while(true) {
        a = in.readInt();
        b = in.readInt();
        if(a == -1) break;
        if(a > b) swap(a, b);
        ans = min(b - a, 100 + a - b);
        out(ans, '\n');
    }
}

