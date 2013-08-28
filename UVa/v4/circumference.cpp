#include <cstdio>
#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>

#define PI 3.141592653589793

// 438 - The Circumference of the Circle
// Algorithm : Geometry, 3 points in a circle

using namespace std;

struct Point {
  double x, y;
};

double calculateRatio(const Point& p1, const Point& p2, const Point& p3) {
  double ma = (p2.y - p1.y) / (p2.x - p1.x);
  double mb = (p3.y - p2.y) / (p3.x - p2.x);

  Point pma, pmb;
  pma.x = ((p1.x + p2.x) / 2.0);
  pma.y = ((p1.y + p2.y) / 2.0);
  pmb.x = ((p2.x + p3.x) / 2.0);
  pmb.y = ((p2.y + p3.y) / 2.0);
  
  double x = (ma * mb * (p1.y - p3.y) + mb * (p1.x + p2.x) - ma * (p2.x + p3.x)) / (2 * (mb - ma));
  double y;
  if(ma != 0)
    y = ((-1 / ma) * (x - pma.x)) + pma.y;
  else
    y = ((-1 / mb) * (x - pmb.x)) + pmb.y;

  double rr = sqrt(pow(p1.x - x, 2.0) + pow(p1.y - y, 2.0));
  
  return rr;
}

int main() {
  Point p1, p2, p3;
  while(scanf("%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) == 6) {
    double r = 0.0;
    if(p2.x - p1.x != 0 and p3.x - p2.x != 0)
      r = calculateRatio(p1, p2, p3);   
    else if(p3.x - p1.x != 0 and p2.x - p3.x != 0)
      r = calculateRatio(p1, p3, p2);
    else if(p1.x - p2.x != 0 and p3.x - p1.x != 0)
      r = calculateRatio(p2, p1, p3);
    else if(p3.x - p2.x != 0 and p1.x - p3.x != 0)
      r = calculateRatio(p2, p3, p1);
    else if(p1.x - p3.x != 0 and p2.x - p1.x != 0)
      r = calculateRatio(p3, p1, p2);
    else if(p2.x - p3.x != 0 and p1.x - p2.x != 0)
      r = calculateRatio(p3, p2, p1);
		printf("%.2lf\n", (2*PI*r));
  }
}
