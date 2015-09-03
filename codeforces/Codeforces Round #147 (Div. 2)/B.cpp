// http://codeforces.com/contest/237/problem/B

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

int main(){ __
  int n;
  cin >> n;

  int mat[55][55];
  int mat2[55][55];

  memset(mat,0,sizeof mat);
  memset(mat2,0,sizeof mat2);

  vector<int> cols;
  vector<int> v;
  vector<int> ans;

  for (int i=0; i<n; ++i){
    int t;
    cin >> t;
    cols.push_back(t);
  }

  for (int i=0; i<n; ++i){
    for (int j=0; j<cols[i]; ++j){
      cin >> mat[i][j];
      v.push_back(mat[i][j]);
    }
  }

  sort (all(v));

  int ind = 0;
  for (int i=0; i<n; ++i){
    for (int j=0; j<cols[i]; ++j){
      mat2[i][j] = v[ind++];
    }
  }

  for (int i=0; i<n; ++i){
    for (int j=0; j<cols[i]; ++j){
      int a = mat2[i][j];
      int b = mat[i][j];
      if (a != b){
        for (int k=0; k<n; ++k){
          int f = false;
          for (int l=0; l<cols[k]; ++l){
            if (mat[k][l]==a){
              ans.push_back(i+1);
              ans.push_back(j+1);
              ans.push_back(k+1);
              ans.push_back(l+1);
              swap(mat[k][l],mat[i][j]);
              f = true;
              break;
            }
          }
          if (f) break;
        }
      }
    }
  }

  cout << ans.size()/4 << endl;
  for (int i=0; i<ans.size(); i+=4)
    cout << ans[i] << " " << ans[i+1] << " " << ans[i+2] << " " << ans[i+3] << endl;

  return 0;
}