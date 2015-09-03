// http://codeforces.com/contest/393/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){__
  int n;
  cin >> n;

  double w[n][n];
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cin >> w[i][j];
    }
  }

  double a[n][n], b[n][n];

  int i=0, j=0;
  for( ;i<n; i++){
    for( j=i;j<n;j++){
        double aa = (w[i][j] + w[j][i]) / 2.0;
        double bb = w[i][j] - ((w[i][j] + w[j][i]) / 2.0);
        a[i][j] = a[j][i] = aa;
        b[i][j] = b[j][i] = bb;
    }
  }

  i=0;j=0;
  for( ;i<n; i++){
    for( j=i;j<n;j++){
        b[j][i] = -b[j][i];
    }
  }
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(i==j) printf("%lf ",w[i][j]);
      else printf("%lf ",a[i][j]);
    }
    printf("\n");
  }

  for(int i=0;i<n;++i){
    int f = true;
    for(int j=0;j<n;++j){
      if(i==j)
        printf("%lf ",0.0);
      else printf("%lf ",b[i][j]);
    }
    printf("\n");
  }


  return 0;
}