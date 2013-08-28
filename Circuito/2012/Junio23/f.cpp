#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#define PI acos(-1.0)

using namespace std;

const double g = 9.8;

double f(double theta, int H, int V) {
    double x;
    double Vy = V * sin(theta * PI / 180.);
    double Vx = V * cos(theta * PI / 180.);

    if(H == 0) {
        x = Vx * Vy * 2 / 9.8;
    }
    else {
        double t1 = ( Vy - sqrt(Vy*Vy + 2*H*g) ) / g;
        double t2 = ( Vy + sqrt(Vy*Vy + 2*H*g) ) / g;

        x = Vx * max(t1, t2);
    }
    return x;
}

int main() {
    int V, H;

    while(~scanf("%d%d", &V, &H) && V != -1 && H != -1) {
        double x = 0.0;
        double lo = 0.0, hi = 90.0;
        for(int i = 0; i <= 30; i++) {
            double t1 = lo + (hi - lo) / 3.;
            double t2 = hi - (hi - lo) / 3.;

            double f1 = f(t1, H, V);
            double f2 = f(t2, H, V);
            x = max(x, max(f1, f2));

            if(f1 > f2) hi = t2; else lo = t1;
        }
        printf("%.6lf\n", x);
    }
    return 0;
}

