// copy from https://blog.csdn.net/hcmdghv587/article/details/108615937
const double EPS = 1e-8;
const double PI = acos(-1.0);
int sgn(double x) {
  if (fabs(x) < EPS)
    return 0;
  if (x < 0)
    return -1;
  return 1;
}
// 点/向量
struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  bool operator==(const Point &other) const {
    return sgn(x - other.x) == 0 && sgn(y - other.y) == 0;
  }
  bool operator<(const Point &other) const {
    return sgn(x - other.x) == 0 ? sgn(y - other.y) < 0 : x < other.x;
  }
  Point operator-(const Point &other) const {
    return {x - other.x, y - other.y};
  }
  Point operator+(const Point &other) const {
    return {x + other.x, y + other.y};
  }
  // cross
  double operator^(const Point &other) const {
    return x * other.y - y * other.x;
  }
  // dot
  double operator*(const Point &other) const {
    return x * other.x + y * other.y;
  }
  double len() const { return hypot(x, y); }
};
typedef Point Vector;
// 直线/线段
struct Line {
  Point src, dest;
  Line() {}
  Line(const Point &_src, const Point &_dest) : src(_src), dest(_dest) {}
  // 通过 ax + by + c = 0 构建直线
  Line(double a, double b, double c) {
    if (sgn(a) == 0) {
      src = {0, -c / b};
      dest = {1, -c / b};
    } else if (sgn(b) == 0) {
      src = {-c / a, 0};
      src = {-c / a, 1};
    } else {
      src = {0, -c / b};
      dest = {1, (-c - a) / b};
    }
  }
  double len() const { return (dest - src).len(); }
  // 求两直线交点(需保证两直线不平行、不重合)
  Point crossPoint(const Line &other) const {
    double a1 = (other.dest - other.src) ^ (src - other.src);
    double a2 = (other.dest - other.src) ^ (dest - other.src);
    return {
        (src.x * a2 - dest.x * a1) / (a2 - a1),
        (src.y * a2 - dest.y * a1) / (a2 - a1),
    };
  }
};
