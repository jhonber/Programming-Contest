// http://codeforces.com/contest/452/problem/B

#include<bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

double d(double x1, double y1, double x2, double y2){ return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1))); }

int main(){ __
  int n,m;
  cin >> n >> m;

  if (n==1 && m==1){
    cout << "1 1\n0 0\n1 0\n0 1" << endl;
    return 0;
  }

  if (!n){
    cout << "0 1\n" << "0 " << m << "\n0 0" << "\n" << "0 " << m-1  << endl;
    return 0;
  }
  if (!m){
    cout << "1 0\n" << n << " " << 0 << "\n0 0" << "\n" << n-1 << " 0" << endl;
    return 0;
  }

  double d1 = d(n,m,0.0,1.0);
  double d2 = d(n,m,1.0,0.0);
  double d3 = d(0,0,n-1,m);
  double d4 = d(0,0,n,m-1);

  double mmax = 0.0;
  int ans = -111;

  if (d1>d2){
    if (d3>d4){
      double tmp = d1 + d(n,m,0.0,0.0) + d3;
      mmax = max(tmp,mmax);
      ans = 1;
    }
    else {
      double tmp = d1 + d(n,m,0.0,0.0) + d4;
      ans = 2;
      mmax = max(tmp,mmax);
    }
  }
  else {
    if (d3>d4){
      double tmp = d2 + d(n,m,0.0,0.0) + d3;
      mmax = max(tmp,mmax);
      ans = 3;
    }
    else {
      double tmp = d2 + d(n,m,0.0,0.0) + d4;
      mmax = max(tmp,mmax);
      ans = 4;
    }
  }

  double tmp  = d(0.0,0.0,n,m) + d(n,m,n,0.0) + d(n,0.0,0.0,m);
  double tmp1 = d(0.0,0.0,n,m) + d(n,m,0.0,m) + d(0.0,m,n,0.0);

  if (max(tmp,tmp1) > mmax){
    if (tmp>tmp1)
      ans = -1;
    else
      ans = 0;
  }

  if (ans==-1)
    cout << "0 0\n" << n << " " << m << "\n" << n << " 0" << "\n" << "0 " << m << endl;
  else if (ans==0)
    cout << "0 0\n" << n << " " << m << "\n" << "0 " << m << "\n" << n << " 0" << endl;
  else if (ans==1)
    cout << "0 1\n" << n << " " << m << "\n" << "0 0\n" << n-1 << " " << m << endl;
  else if (ans==2)
    cout << "0 1\n" << n << " " << m << "\n" << "0 0\n" << n << " " << m-1 << endl;
  else if (ans==3)
    cout << "1 0\n" << n << " " << m << "\n" << "0 0\n" << n-1 << " " << m << endl;
  else if (ans=4)
    cout << "1 0\n" << n << " " << m << "\n" << "0 0\n" << n << " " << m-1 << endl;

  return 0;
}