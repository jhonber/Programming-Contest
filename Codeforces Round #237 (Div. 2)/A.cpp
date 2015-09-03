// http://codeforces.com/contest/404/problem/A

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

int main(){
  int n;
  cin >> n;

  char mat[n][n];
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> mat[i][j];
    }
  }

  char t = mat[0][0];
  for(int i=0, i2=0, j=0, j2=n-1 ; i<n; ++i,++j, i2++, j2--){
    if(mat[i][j] != mat[i2][j2] || (i==i2 && j==j2 && t != mat[i][j])){
      cout << "NO";
      return 0;
    }
    else
      mat[i][j] = mat[i2][j2] = '*';
  }

  set<char> st;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(mat[i][j] != '*')
        st.insert(mat[i][j]);
    }
  }

  if(st.size()==1 && *st.begin() != t )
    cout << "YES";
  else
    cout << "NO";

  return 0;
}