#include <iostream>
#include <limits.h>

using namespace std;

struct Point {
  int x;
  int y;
};

bool on_segment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;

  return false;
}

int Direction(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0; // collinear

  return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
  int d1 = Direction(p1, q1, p2);
  int d2 = Direction(p1, q1, q2);
  int d3 = Direction(p1, q1, q2);
  int d4 = Direction(p2, q2, q1);

  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
      ((d3 > 0 && d4 < 0) || (d3 < 0) and (d4 > 0))) {
    return true;
  }

  else if (d1 == 0 && on_segment(p1, q1, p2)) {
    return true;
  } else if (d2 == 0 && on_segment(p1, q1, q2)) {
    return true;
  } else if (d3 == 0 && on_segment(p1, q1, q2)) {
    return true;
  } else if (d4 == 0 && on_segment(p2, q2, q1)) {
    return true;
  } else
    return false;
}

int main() {
  struct Point p1 = {1, 1}, q1 = {10, 1};
  struct Point p2 = {1, 2}, q2 = {10, 2};

  doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";
}