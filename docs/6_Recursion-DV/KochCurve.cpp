#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

const double th = M_PI*60/180.0;

void Koch(pair<double, double> a, pair<double, double> b, int n){
  if (n == 0){
    return;
  }
  pair<double, double> s, t, u;
  double u_x, u_y;
  
  s = make_pair((2*a.first+b.first)/3, (2*a.second+b.second)/3);
  t = make_pair((a.first+2*b.first)/3, (a.second+2*b.second)/3);
  u_x = (t.first - s.first) * cos(th) - (t.second - s.second)*sin(th) + s.first;
  u_y = (t.first - s.first) * sin(th) + (t.second - s.second)*cos(th) + s.second;
  u = make_pair(u_x, u_y);

  Koch(a, s, n-1);
  printf("%.8lf %.8lf\n", s.first, s.second);
  Koch(s, u, n-1);
  printf("%.8lf %.8lf\n", u.first, u.second);
  Koch(u, t, n-1);
  printf("%.8lf %.8lf\n", t.first, t.second);
  Koch(t, b, n-1);
}

int main(){
  pair<double, double> a;
  pair<double, double> b;
  int n;


  a = make_pair(0, 0);
  b = make_pair(100, 0);
  cin >> n;

  printf("%.8lf %.8lf\n", a.first, a.second);
  Koch(a, b, n);
  printf("%.8lf %.8lf\n", b.first, b.second);

  return 0;
}