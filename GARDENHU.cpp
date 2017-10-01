/*
      Using Graham Scan, done during the learning of algorithm
      Date: 9/4/2017
*/

#include <bits/stdc++.h>

using namespace std;

class Point{
      public:
            int x, y;
            Point(){
                  x = y = 0;
            }
            Point(int _x, int _y){
                  x = _x;
                  y = _y;
            }
            bool operator < (Point a){
                  if(y != a.y)
                        return y<a.y;
                  return x < a.x;
            }
};

typedef long long ll;

Point pivot;
int n, a, b;
vector<Point> dat;

ll sqDist(Point a, Point b){
      ll dx = b.x - a.x;
      ll dy = b.y - a.y;
      return dx*dx + dy*dy;
}

// return -1 for counter clock wise
int ccw(Point a, Point b, Point c){
      int area = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
      if(area>0)
            return -1;
      else if(area <0)
            return 1;
      return 0;
}

bool polarOrder(Point a, Point b){
      int order = ccw(pivot, a, b);
      if(order==0)
            return sqDist(pivot, a) < sqDist(pivot, b);
      return (order == -1);
}

ll solveGrahamScan(){
      ll ans = 0;
      if(n<3)
            return 0;
      int leastY = 0;
      for(int i=1; i<n; i++){
            if(dat[i] < dat[leastY])
                  leastY = i;
      }
      Point tmp = dat[leastY];
      dat[leastY] = dat[0];
      dat[0] = tmp;
      pivot = dat[0];
      sort(dat.begin()+1, dat.end(), polarOrder);
      // for(auto it : dat){
      //       cout<<it.x<<" "<<it.y<<"\n";
      // }
      vector<Point> hull;
      hull.push_back(dat[0]);
      hull.push_back(dat[1]);
      hull.push_back(dat[2]);
      for(int i=3; i<n; i++){
            Point top = hull.back();
            hull.pop_back();
            while(ccw(hull.back(), top, dat[i]) != -1){
                  top = hull.back();
                  hull.pop_back();
            }
            hull.push_back(top);
            hull.push_back(dat[i]);
      }
      int sz = hull.size();
      // for(auto it : hull){
      //       cout<<it.x<<" "<<it.y<<"\n";
      // }
      for(int i=0; i<sz; i++){
            // cout<<i<<" "<<((i+1)%sz)<<" "<<sqrt(sqDist(hull[i], hull[(i+1)%sz]))<<"\n";
            ans += sqrt(sqDist(hull[i], hull[(i+1)%sz]));
      }
      return ans;
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      // cout<<ccw(Point(0, 0), Point(0, 1), Point(0, 2))<<"\n";
      cin>>n;
      for(int i=0; i<n; i++){
            cin>>a>>b;
            dat.push_back(Point(a, b));
      }
      cout<<solveGrahamScan()<<"\n";
      return 0;
}
