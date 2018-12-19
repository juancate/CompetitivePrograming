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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> numbers(n), count(10, 0);
    bool zero = false;

    REP(i, 0, n) {
        cin >> numbers[i];
        if(numbers[i] == 0) zero = true;
        count[numbers[i]]++;
    }

    if(!zero) {
        cout << -1 << endl;
    } else {
        stringstream ss, fours, twos, fives, ones;
        for(int i = 9; i > 0; i--) {
            if(i % 3 != 0) {
                int x = (count[i]) / 3;
                REP(k, 0, 3 * x) ss << i;

                if(i == 8) {
                    x = count[i] % 3;
                    if(x > 0) {
                        int y = count[4] % 3;
                        int z = count[2] % 3;
                        while(count[4] >= count[2] && y >= x) {
                            ss << 8;
                            fours << 4;
                            count[4]--;
                            x--, y--;
                        }
                        while(z > 0 && z >= 2*x) {
                            ss << 8;
                            twos << 2 << 2;
                            count[2] -= 2;
                            z -= 2;
                            x--;
                        }
                    }
                }

                if(i == 4) {
                    x = count[i] % 3;
                    ss << fours.str();
                    if(x > 0) {
                        int y = count[2] % 3;
                        int z = count[1] % 3;

                        while(count[2] >= count[1] && y >= x) {
                            ss << 4;
                            twos << 2;
                            count[2]--;
                            x--, y--;
                        }
                        while(z > 0 && z >= 2*x) {
                            ss << 4;
                            ones << 1 << 1;
                            count[1] -= 2;
                            z -= 2;
                            x--;
                        }
                    }
                }

                if(i == 2) {
                    ss << twos.str();
                    x = count[i] % 3;

                    if(x > 0) {
                        int y = count[2] % 3;
                        if(y >= x) {
                            REP(k, 0, x) ss << 2;
                            REP(k, 0, x) ones << 1;
                            count[1] -= x;
                        }
                    }
                }

                if(i == 7) {
                    x = count[i] % 3;
                    if(x > 0) {
                        int y = count[5] % 3;
                        int z = count[1] % 3;

                        while(count[5] >= count[1] && y >= x) {
                            ss << 7;
                            fives << 5;
                            count[5]--;
                            x--, y--;
                        }
                        while(z > 0 && z >= 2*x) {
                            ss << 7;
                            ones << 1 << 1;
                            count[1] -= 2;
                            z -= 2;
                            x--;
                        }
                    }
                }

                if(i == 5) {
                    x = count[i] % 3;
                    ss << fives.str();
                    if(x > 0) {
                        int y = count[1] % 3;
                        if(y >= x) {
                            REP(k, 0, x) ss << 5;
                            REP(k, 0, x) ones << 1;
                            count[1] -= x;
                        }
                    }
                }

                if(i == 1) ss << ones.str();

            } else {
                REP(k, 0, count[i]) ss << i;
            }
        }
        if(ss.str().size() > 0)
            REP(k, 0, count[0]) ss << 0;
        else if(count[0] > 0) ss << 0;
        cout << ss.str() << endl;
    }
}

