#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    const int T = 1;
    const int N = 1000000;
    const int M = 10000;

    cout << T << endl;
    cout << N << ' ' << M << endl;

    for(int i = 0; i < M; i++) {
        int w = 1, x = 2, y = N, z = 100000;
        cout << w << ' ' << x << ' ' << y << ' ' << z << endl;
    }
}
