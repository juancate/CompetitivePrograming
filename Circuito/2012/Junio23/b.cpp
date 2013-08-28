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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

// Topics : Polar angles, Geometry, Sorting.

typedef pair<int,int> point;
typedef pair<point, point> line;

#define x first
#define y second

point start;
vector<point> polygon;
vector<line> part_lines;
set<line> edges;

bool cmp(point a, point b) {
    return atan2(a.y - start.y, a.x - start.x) > atan2(b.y - start.y, b.x - start.x);
}

bool contains(point a, point b) {
    if(a > b) return edges.count( line(b, a) );
    return edges.count( line(a, b) );
}

void insert(point a, point b) {
    if(a > b) edges.insert( line(b, a) );
    else edges.insert( line(a, b) );
}

void insert_part(point a, point b) {
    if(a > b) part_lines.push_back( line(b, a) );
    else part_lines.push_back( line(a, b) );
}

void erase_lines() {
    sort(ALL(part_lines));

    REP(i, 0, part_lines.size() - 1) {
        int j = i+1, cnt = 0;
        while(part_lines[i] == part_lines[j]) j++, cnt++;
        if(cnt > 0) edges.erase( part_lines[i] );
        i = j-1;
    }
}

int main() {
    int N;
    while(scanf("%d", &N) && N != -1) {
        polygon.clear();
        edges.clear();
        part_lines.clear();

        REP(i, 0, N-2) {
            int x1, y1, x2, y2, x3, y3;
            scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
            point p1(x1, y1), p2(x2, y2), p3(x3, y3);

            insert(p1, p2);
            insert(p1, p3);
            insert(p2, p3);

            insert_part(p1, p2);
            insert_part(p1, p3);
            insert_part(p2, p3);

            polygon.push_back(p1); polygon.push_back(p2); polygon.push_back(p3);
        }

        sort(ALL(polygon));
        erase_lines();

        polygon.resize(unique(ALL(polygon)) - polygon.begin());

        int pivot = 0;
        start = polygon[pivot];
        
        sort(polygon.begin()+1, polygon.end(), cmp);

        REP(i, 1, polygon.size()) {
            int j = i;

            while(!contains(start, polygon[j])) j++;

            swap(polygon[i], polygon[j]);
            start = polygon[i];
        }

        REP(i, 0, polygon.size()) {
            if(i) printf(" ");
            printf("%d %d", polygon[i].x, polygon[i].y);
        }
        puts("");
    }
}

