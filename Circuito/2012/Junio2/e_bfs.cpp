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

#define D(x) cerr << #x << " = " << (x) << endl
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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 60 + 10;

struct Element {
    int n[3], diff, cost;

    Element(int ax = 0, int bx = 0, int cx = 0, int costx = 0) {
        n[0] = ax, n[1] = bx, n[2] = cx;
        cost = costx;
    }

    bool operator>(const Element& a) const {
        return cost > a.cost;
    }

    bool operator!=(const Element& a) const {
        return !equal(n, n + 3, a.n);
    }

    void move(int from, int to) {
        n[from] -= n[to];
        n[to] *= 2;
        cost++;
    }

    bool valid() {
        return n[0] >= 0 && n[1] >= 0 && n[2] >= 0;
    }

    int index() const {
        return 60 * n[0] + n[1];
    }
};

bool visited[MAXN][MAXN][MAXN];
char buffer[MAXN];
vector<string> output;

bool solve(int ax, int bx, int cx) {
    memset(visited, false, sizeof(visited));
    queue<Element> q;
    Element backTrace[3661];

    q.push(Element(ax, bx, cx, 0));
    visited[ax][bx][cx] = true;

    int a, b, c;

    while(!q.empty()) {
        Element el = q.front();
        q.pop();

        a = el.n[0];
        b = el.n[1];
        c = el.n[2];

        if(a == b && b == c) {
            Element p = el;
            while(backTrace[p.index()] != Element()) {
                sprintf(buffer, "%4d%4d%4d", p.n[0], p.n[1], p.n[2]);
                output.insert(output.begin(), buffer);
                p = backTrace[p.index()];
            }
            sprintf(buffer, "%4d%4d%4d", p.n[0], p.n[1], p.n[2]);
            output.insert(output.begin(), buffer);
            return true;
        }

        REP(i, 0, 3) REP(j, 0, 3) if(i != j) {
            Element next = el;
            next.move(i, j);
            if(next.valid() && !visited[next.n[0]][next.n[1]][next.n[2]]) {
                backTrace[next.index()] = el;
                q.push(next);
                visited[next.n[0]][next.n[1]][next.n[2]] = true;
            }
        }
    }
    return false;
}

int main() {
    int a, b, c;
    while(~scanf("%d%d%d", &a, &b, &c)) {
        output.clear();
        if(solve(a, b, c)) {
            REP(i, 0, output.size()) {
                puts(output[i].c_str());
            }
        } else {
            sprintf(buffer, "%4d%4d%4d", a, b, c);
            puts(buffer);
        }
        puts("============");
    }
}

