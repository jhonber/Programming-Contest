// http://codeforces.com/contest/281/problem/C

# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>
# include <climits>
# define FR(i,n) for(int i = 0; i < n; i++)
# define PI  3.1415926535897931
# define PB push_back
#define D(x) cout<< #x " = "<<(x)<<endl

using namespace std;

struct point
{
    double x;
    double y;
};

struct edge
{
    point p1;
    point p2;
};

struct vect
{
    double x;
    double y;
};

typedef vector<double> vdd;
typedef vector<point> vdp;
typedef vector<edge> vpe;



vdp rotate(vdp points, double angle)
{
   vdp rpoints;
   FR(i,points.size())
   {
      point p;
      p.x = (points[i].x*cos(angle)) - (points[i].y*sin(angle));
      p.y = (points[i].x*sin(angle)) + (points[i].y*cos(angle));
      rpoints.PB(p);
   }
   return rpoints;
}



vpe edges(vdp rpoints)
{
    vpe edges;
    FR(i,3)
    {
       edge e;
       e.p1 = rpoints[i];
       e.p2 = rpoints[i+1];
       edges.PB(e);
    }
    edge e;
    e.p1 = rpoints[3];
    e.p2 = rpoints[0];
    edges.PB(e);
    return edges;
}

bool inside(point p, edge e)
{
   vect v1;
   vect v2;   
   v1.x = p.x - e.p1.x;
   v1.y = p.y - e.p1.y;
   v2.x = e.p2.x - e.p1.x;
   v2.y = e.p2.y - e.p1.y;
   
   double cross =  (v1.x*v2.y) - (v1.y*v2.x);
   if (cross < 0) return false;
   else return true;
   
}

point intersection(point p, point q, edge e){
  
  point w;
  double x0 = p.x;
  double y0 = p.y;
  double x1 = q.x;
  double y1 = q.y;
  double x2 = e.p1.x;
  double y2 = e.p1.y;
  double x3 = e.p2.x;
  double y3 = e.p2.y;
  #ifndef EPS
  #define EPS 1e-9
  #endif
  double t0 = (y3-y2)*(x0-x2) - (x3-x2)*(y0-y2);
  double t1 = (x1-x0)*(y2-y0) - (y1-y0)*(x2-x0);
  double det = (y1-y0)*(x3-x2) - (y3-y2)*(x1-x0);
  if( fabs(det) < EPS ){
    if(fabs(t0) < EPS || fabs(t1) < EPS){
      //same line
      w.x =INT_MAX;
      w.y =INT_MAX;
      return w;
    }
    else{
      //just parallel
      w.x = -INT_MAX;
      w.y = -INT_MAX;
      return w;
    }
  }
  else{
    t0 /= det;
    t1 /= det;
    double x = x0 + t0*(x1-x0);
    double y = y0 + t0*(y1-y0);
    //intersection is point (x,y)
   
    w.x = x;
    w.y =y;
    return w;
  }
}
   
vdp sutherland_h(vdp points, vdp rpoints, vpe edges)
{
   vdp outputList = points;
   FR(i,edges.size())
   {
      vdp inputList = outputList;
      outputList.clear();
      //D(inputList.size());
      point s = inputList[inputList.size()-1];
      //D(2);
      FR(j,inputList.size())
      {
        //D(inside(inputList[j], edges[i]));
        if(inside(inputList[j], edges[i]))
        {
           if(!inside(s,edges[i]))
               outputList.PB(intersection(s,inputList[j],edges[i]));
           outputList.PB(inputList[j]);
        }
        else if(inside(s, edges[i]))
           outputList.PB(intersection(s,inputList[j],edges[i]));
        s=inputList[j];           
      }
    }
    return outputList;
}

double PolygonArea(vdp p){
    double r = 0.0;
    for (int i=0; i<p.size(); ++i){
        int j = (i+1) % p.size();
        r += p[i].x*p[j].y - p[j].x*p[i].y;
     }
    return fabs(r/2.0);
}
int main()
{
   double w,h,alpha;
   cin>> w >> h >> alpha;
   if( w == h && alpha == 90.0) {
      printf("%lf\n",w*h);
      return 0;
   }
   if(alpha == 180.0 || alpha == 0.0){
      printf("%lf\n",w*h);
      return 0;
   }
   
   double angle = (alpha*PI)/180.0;
  //D(angle);
   
   vdp points;
   double dx [4] = {-1.0,1.0,1.0,-1.0};
   double dy [4] = {1.0,1.0,-1.0,-1.0};
  
   FR(i,4)
   {
      point p;
      p.x = (w/2.0)*dx[i];
      p.y = (h/2.0)*dy[i];
      points.PB(p);
   }
   
   vdp rpoints = rotate(points, angle);
   vpe edg = edges(rpoints);
   
   /*FR(i,4)
   {
       cout<<points[i].x<<" "<<points[i].y<<endl;
       //cout<< edg[i].p1.x<<" "<<edg[i].p1.y<<endl;//<<" "<<edg[i].p2.x<<" "<<edg[i].p2.y<<endl;
   }*/
       
   vdp clip_polygon = sutherland_h(points, rpoints, edges(rpoints));  
   printf("%lf\n",PolygonArea(clip_polygon));
   return 0;
}