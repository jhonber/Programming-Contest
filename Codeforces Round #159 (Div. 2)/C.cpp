// http://codeforces.com/contest/257/problem/C

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl;

const double PI = 3.141592653589793;

int main(){
  int n;
  scanf("%d",&n);

  double ang[n];

  for(int i=0; i<n; ++i){
    double x,y;
    scanf("%lf %lf",&x,&y);

    double t = atan2(y,x);
    if(t < 0)
      t += 2*PI;

    ang[i] = t*180.0 / PI;
  }

  sort(ang,ang+n);

  double maxdif = (360.0 - ang[n-1]) + ang[0];

  for(int i=1; i<n; ++i)
    maxdif = max( maxdif, ang[i]-ang[i-1] );

  printf("%lf\n",360.0-maxdif);

  return 0;
}