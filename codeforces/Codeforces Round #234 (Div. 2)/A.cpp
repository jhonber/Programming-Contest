// http://codeforces.com/contest/400/problem/A

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

int v[12] = {1,12,2,6,3,4,4,3,6,2,12,1};
string s;

int f(int f, int c){

  char mat[f][c];
  int k = 0;
  for(int i=0; i<f; ++i){
    for(int j=0; j<c; ++j){
      mat[i][j] = s[k++];
    }
  }

  for(int i = 0; i<c; ++i){
    char ant = mat[0][i];
    int ff = true;
    if(ant == 'O') continue;
    for(int j = 0; j<f; ++j){
      if(ant != mat[j][i])
        ff = false;
    }
    if(ff)
      return true;
  }
  return false;
}

int main(){__
  int n;
  cin >> n;

  for(int i=0; i<n; ++i){
    cin >> s;
    vector<int> ans;

    for(int i=0; i<12; i+=2){
      if(f(v[i],v[i+1]))
        ans.push_back( i );
    }

    cout << ans.size();
    for(int i=0; i<ans.size(); ++i)
      cout << " " << v[ans[i]] << "x" << v[ans[i]+1];

    cout << endl;
  }

  return 0;
}