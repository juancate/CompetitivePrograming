#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAXPOLY 600
#define EPSILON 1e-9

/*
  Algorithm: Convex Hull (Graham Scan) ignoring collinear points
*/

typedef struct point {
    int x, y;
} point;

typedef struct polygon {
    int n;
    point p[MAXPOLY];
} polygon;


double signed_triangle_area(point a, point b, point c) {
    return ( (a.x * b.y - a.y * b.x + a.y * c.x
              - a.x * c.y + b.x * c.y - c.x * b.y ) / 2.0 );
}

int ccw(point a, point b, point c) {
    return (signed_triangle_area(a, b, c) > EPSILON);
}

int cw(point a, point b, point c) {
    return (signed_triangle_area(a, b, c) < EPSILON);
}

int collinear(point a, point b, point c) {
    return (fabs(signed_triangle_area(a, b, c)) <= EPSILON);
}

point first_point;

double distance(point a, point b) {
    double xx, yy, cc;
    xx = (a.x - b.x);
    yy = (a.y - b.y);
    xx *= xx;
    yy *= yy;
    cc = xx + yy;
    return sqrt(cc);
}

void copy_point(point p1, point* p2) {
    p2->x = p1.x;
    p2->y = p1.y;
}

int leftlower(const void* a, const void* b) {
    point* p1 = (point *)a;
    point* p2 = (point *)b;

    if ( p1->y < p2->y ) return -1;
    if ( p1->y > p2->y ) return 1;

    if ( p1->x < p2->x ) return -1;
    if ( p1->x > p2->x ) return 1;

    return 0;
}

void sort_and_remove_duplicates(point in[], int* n) {
    int i, oldn, hole;

    qsort(in, *n, sizeof(point), leftlower);

    oldn = *n;
    hole = 1;

    for (i = 1; i < (oldn - 1); i++) {
        if ((in[hole-1].x == in[i].x) && (in[hole-1].y == in[i].y))
            (*n)--;
        else {
            copy_point(in[i], &in[hole]);
            hole++;
        }
    }
    copy_point(in[oldn-1], &in[hole]);
}

int smaller_angle(const void* a, const void* b) {
    point* p1 = (point *)a;
    point* p2 = (point *)b;

    if (collinear(first_point, *p1, *p2)) {
        if (distance(first_point, *p1) <= distance(first_point, *p2))
            return -1;
        else
            return 1;
    }

    if(ccw(first_point, *p1, *p2))
        return -1;
    else
        return 1;
}

void convex_hull(point in[], int n, polygon* hull) {
    int i, top;

    if(n <= 3) {
        for (i = 0; i < n; i++) {
            copy_point(in[i], &hull->p[i]);
        }
        hull->n = n;
        return;
    }

    sort_and_remove_duplicates(in, &n);
    copy_point(in[0], &first_point);

    qsort(&in[1], n-1, sizeof(point), smaller_angle);

    for(i = 0; i < n; i++)
        fprintf(stderr, "in[%d] = (%d, %d)\n", i, in[i].x, in[i].y);

    copy_point(first_point, &hull->p[0]);
    copy_point(in[1], &hull->p[1]);

    copy_point(first_point, &in[n]);
    top = 1;
    i = 2;

    while(i <= n) {
        while (top > 0 && !ccw(hull->p[top-1], hull->p[top], in[i]) )
            top = top-1;
        top++;
        copy_point( in[i], &hull->p[top] );
        i++;
    }

    hull->n = top;
}

int main() {
    int K, N, delim, i, x, y;

    scanf("%d", &K);
    printf("%d\n", K);
    while(K--) {
        scanf("%d", &N);

        point poly[N+10];

        for (i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            poly[i].x = x; poly[i].y = y;
        }
        scanf("%d", &delim);

        polygon hull;
        convex_hull(poly, N, &hull);

        printf("%d\n", hull.n + 1);
        for (i = 0; i <= hull.n; i++) {
            printf("%d %d\n", hull.p[i].x, hull.p[i].y);
        }

        if(K) printf("%d\n", delim);
    }

    return 0;
}
