#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

using namespace std;

const double EPS = 1e-9;

inline
int compareTo(double x, double y, double tol=EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  double x, y;
  point(double _x=0, double _y=0) {
    x = _x; y = _y;
  }
};

struct person {
  double x, y, p, q;
  string name;
  bool alive;

  person(double _x=0, double _y=0, double _p=0, double _q=0, bool a=true) {
    x = _x; y = _y; p = _p; q = _q;
    alive = a;
  }

  void normalize() {
    double norm = sqrt(p*p + q*q);
    fprintf(stderr, "norm = %lf\n", norm);
    p /= norm;
    q /= norm;
  }

  void print(FILE* f = stderr) {
    fprintf(f, "%s => (%lf, %lf) , (%lf, %lf)\n", name.c_str(), x, y, p, q);
  }
};

struct map_cmp {
  bool operator()(const double& t1, const double& t2) const {
    return compareTo(t1,t2) < 0;
  }
};

typedef pair<double,string> pds;
struct set_cmp {
  bool operator()(pds p1, pds p2) {
    if (compareTo(p1.first, p2.first) == 0)
      return p1.second < p2.second;
    return compareTo(p1.first, p2.first) < 0;
  }
};

int N, B, H;
vector<person> p;
map<double,set<int>,map_cmp> m;
map<double,set<int>,map_cmp>::iterator it;
set<pds,set_cmp> answer;
vector<point> board[4];

void build_board() {
  for (int i = 0; i < 4; i++)
    board[i].clear();
  board[0].push_back(point(0, 0)); board[0].push_back(point(B, 0));
  board[1].push_back(point(B, 0)); board[1].push_back(point(B, H));
  board[2].push_back(point(B, H)); board[2].push_back(point(0, H));
  board[3].push_back(point(0, H)); board[3].push_back(point(0, 0));
}

bool border_intersection(int i, int j, double& t) {
  // line intersection
  double v1x = p[i].p;
  double v1y = p[i].q;
  double v2x = (board[j][0].x - board[j][1].x); // normalize?
  double v2y = (board[j][0].y - board[j][1].y);

  double norm = sqrt(v2x*v2x + v2y*v2y);
  v2x /= norm;
  v2y /= norm;

  double det = v1x * v2y - v2x * v1y;

  if (fabs(det) < EPS)
    return false;

  double A = (p[i].x - board[j][0].x);
  double B = (p[i].y - board[j][1].y);

  t = (v1y * A - v1x * B) / det;
  double s = (v2y * A - v2x * B) / det;

  if (compareTo(t, s) == 0 && compareTo(0, t) <= 0) {
    return true;
  }

  return false;
}

// Casos:
// Van en la misma dirección y no se alcanzan.
// Paralelos en direcciones opuestas

bool intersects(int i, int j, double& t) {
  double a, b, c, d, rx, ry, det;

  a = p[i].p, b = p[j].p;
  c = p[i].q, d = p[j].q;

  det = a*d - b*c;

  if (fabs(det) < EPS)
    return false;

  rx = p[j].x - p[i].x;
  ry = p[j].y - p[i].y;

  t = (a * ry - rx * c) / det;
  double s = (b * ry - rx * d) / det;

  if (compareTo(t, s) == 0 && compareTo(0, t) <= 0) {
    fprintf(stderr, ">>> t => %lf s => %lf\n", t, s);
    return true;
  }

  return false;
}

bool collides(int k) {
  int cnt = 0;
  double t;

  for (int i = 0; i < p.size(); i++) {
    if (i != k && p[i].alive && intersects(i,k,t)) {
      cnt++;
      m[t].insert(k);
      m[t].insert(i);
    }
  }
  return cnt != 0;
}

inline bool still(int i) {
  return compareTo(p[i].p, 0) == 0 && compareTo(p[i].q, 0) == 0;
}

inline void swap_person(int i, int j, double t) {
  // calculate intersection pos
  double x = p[i].x + t * p[i].p;
  double y = p[i].y + t * p[i].q;

  p[i].x = p[j].x = x;
  p[i].y = p[j].y = y;
  swap(p[i].name, p[j].name);
}

void solve() {
  double curr_time = 0;

  while (!p.empty()) {
    fprintf(stderr, "p.size = %d\n", p.size());
    m.clear();
    vector<person> curr;
    for (int i = 0; i < p.size(); i++) {
      fprintf(stderr, "i => %d name => %s\n", i, p[i].name.c_str());
      if (!collides(i)) {
        if (still(i)) {
          p[i].alive = false;
        }
        else {
          double t;
          for (int j = 0; j < 4; j++)
            if (border_intersection(i, j, t))
              break;
          p[i].alive = false;
          answer.insert(make_pair(t, p[i].name));
        }
      }
    }

    it = m.begin();
    double t = it->first;
    set<int> s = it->second;
    curr_time += t;
    fprintf(stderr, "t => %lf s_size => %d\n", t, s.size());

    if (s.size() == 2) {
      int i = *s.begin();
      s.erase(s.begin());
      int j = *s.begin();
      swap_person(i,j,t);
    }
    else if (s.size() > 2) {
      foreach (sit, s) {
        int i = *sit;
        p[i].alive = false;
        answer.insert(make_pair(curr_time, p[i].name));
      }
    }

    // Just keep alive persons
    for (int i = 0; i < p.size(); i++) {
      if (p[i].alive)
        curr.push_back(p[i]);
    }
    p = curr;
  }

  set<pds,set_cmp>::iterator sit = answer.end();
  sit--;
  cout << sit->second << endl;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  int t;
  cin >> t;

  while (t--) {
    cin >> N >> B >> H;

    answer.clear();
    p.assign(N, person());
    for (int i = 0; i < N; i++) {
      cin >> p[i].x >> p[i].y >> p[i].p >> p[i].q >> p[i].name;
      p[i].p -= p[i].x, p[i].q -= p[i].y;
      p[i].normalize();
      p[i].print();
    }

    build_board();
    solve();
    fprintf(stderr, "END OF CASE\n");
  }

  return 0;
}
