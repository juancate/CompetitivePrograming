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

bool visited[MAXN][MAXN][MAXN];
char buffer[MAXN];
vector<string> output;

struct Element {
    int n[3], diff, cost;
    Element* parent;

    Element() {}

    Element(int ax, int bx, int cx, int costx, Element* p = 0) {
        n[0] = ax, n[1] = bx, n[2] = cx;
        cost = costx;
        parent = p;
    }
};

struct CompareElement : public std::binary_function<Element*, Element*, bool> {
    bool operator()(const Element* a, const Element* b) const {
        return a->cost > b->cost;
    }
};

typedef priority_queue< Element*, vector<Element*>, CompareElement > PriorityQueue;

bool solve(int ax, int bx, int cx) {
    memset(visited, false, sizeof(visited));
    PriorityQueue pq;

    pq.push(new Element(ax, bx, cx, 0));
    visited[ax][bx][cx] = true;

    int a, b, c;

    while(!pq.empty()) {
        Element* el = pq.top();
        pq.pop();

        a = el->n[0];
        b = el->n[1];
        c = el->n[2];

        if(a == b && b == c) {
            sprintf(buffer, "%4d%4d%4d", el->n[0], el->n[1], el->n[2]);
            output.insert(output.begin(), buffer);

            Element* p = el->parent;
            while(p != 0) {
                sprintf(buffer, "%4d%4d%4d", p->n[0], p->n[1], p->n[2]);
                output.insert(output.begin(), buffer);
                Element* tmp = p;
                p = p->parent;
                delete tmp;
            }
            return true;
        }

        if(a >= b && !visited[a - b][2 * b][c]) {
            pq.push(new Element(a - b, 2 * b, c, el->cost + 1, el));
            visited[a - b][2 * b][c] = true;
        }
        if(a >= c && !visited[a - c][b][2 * c]) {
            pq.push(new Element(a - c, b, 2 * c, el->cost + 1, el));
            visited[a - c][b][2 * c] = true;
        }
        if(b >= a && !visited[2 * a][b - a][c]) {
            pq.push(new Element(2 * a, b - a, c, el->cost + 1, el));
            visited[2 * a][b - a][c] = true;
        }
        if(b >= c && !visited[a][b - c][2 * c]) {
            pq.push(new Element(a, b - c, 2 * c, el->cost + 1, el));
            visited[a][b - c][2 * c] = true;
        }
        if(c >= a && !visited[2 * a][b][c - a]) {
            pq.push(new Element(2 * a, b, c - a, el->cost + 1, el));
            visited[2 * a][b][c - a] = true;
        }
        if(c >= b && !visited[a][2 * b][c - b]) {
            pq.push(new Element(a, 2 * b, c - b, el->cost + 1, el));
            visited[a][2 * b][c - b] = true;
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
            output.push_back(buffer);
            puts(output[0].c_str());
        }
        puts("============");
    }
}

