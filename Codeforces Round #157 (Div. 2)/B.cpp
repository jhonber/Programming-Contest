// http://codeforces.com/contest/259/problem/B

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

int mat[3][3];
int ans = 0;

int main(){__

  int n = 100000;

  for(int x=0; x<3; ++x){
    for(int y=0; y<3; ++y){
      cin >> mat[x][y];
    }
  }


  for(int i=1; i<=n; ++i){
    mat[0][0] = i;
    int tmp = mat[0][0] + mat[0][1] + mat[0][2];
    if( tmp == mat[0][0] + mat[1][0] + mat[2][0] ){
      int x = tmp - (mat[1][0] + mat[1][2]);
      int y = tmp - (mat[2][0] + mat[2][1]);
      mat[1][1] = x;
      mat[2][2] = y;

      set<int> st;
      for(int j=0; j<3; ++j){
        int t = 0;
        for(int k=0; k<3; ++k){
          t += mat[j][k];
        }
        st.insert( t );
      }

      for(int j=0; j<3; ++j){
        int t = 0;
        for(int k=0; k<3; ++k){
          t += mat[k][j];
        }
        st.insert( t );
      }

      int t = 0;
      for(int j=0; j<3; ++j)
        t += mat[j][j];

      st.insert(t);

      t = 0;
      for(int j=0, k=2; k>=0; --k, ++j)
        t += mat[j][k];

      st.insert(t);

      if(st.size()==1){
        for(int j=0; j<3; ++j){
          for(int k=0; k<3; ++k){
            cout << mat[j][k] << " ";
          }
          cout << endl;
        }
        return 0;
      }

    }
    else continue;
  }

  return 0;
}