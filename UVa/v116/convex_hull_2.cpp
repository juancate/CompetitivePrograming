#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)

using namespace std;

typedef long long int64;
typedef complex<int64> pnt;

int64 cross(const pnt& a, const pnt& b) { return imag(conj(a) * b); }
int64 cross(const pnt& a, const pnt& b, const pnt& c) {
    return cross(b - a, c - a);
}

struct compareYX {
    bool operator()(const pnt& a, const pnt& b) const {
        if (a.real() == b.real())
            return a.imag() < b.imag();
        else
            return a.real() < b.real();
    }

    bool operator()(const pair<pnt, int>& a, const pair<pnt, int>& b) const {
        return (*this)(a.first, b.first);
    }
};

struct compareAngle {
    pnt base;

    compareAngle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const {
        return cross(base, a, b) > 0;
    }

    bool operator()(const pair<pnt, int> &a, const pair<pnt, int> &b) const {
        return (*this)(a.first, b.first);
    }
};

int main() {
    int T, N;
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        vector<pnt> poly;

        int count = 0;
        REP(i, 0, N) {
            int64 x, y;
            char c;
            scanf("%lld%lld %c", &x, &y, &c);
            if(c == 'Y') {
                poly.push_back( pnt(x, y) );
                //D(poly[count]); D(x); D(y);
                count++;
            }
        }
        vector<pnt>::iterator m = min_element(poly.begin(), poly.end(), compareYX());
        swap(*m, *poly.begin());
        sort(poly.begin(), poly.end(), compareAngle(poly[0]));

        printf("%d\n", count);

        REP(i, 0, count) {
            printf("%lld %lld\n", poly[i].real(), poly[i].imag());
        }
    }
}


