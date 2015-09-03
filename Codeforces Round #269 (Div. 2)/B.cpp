// http://codeforces.com/contest/471/problem/B

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

  vector<int> v[2222];

  for (int i=0; i<n; ++i) {
    int a;
    cin >> a;
    v[a].push_back(i+1);
  }

  int f = 0;
  int ff = 0;
  int ans[3][n];
  for (int i=0; i<2222; ++i) {
     if (v[i].size() >= 2 )
       f++;
     if (v[i].size() >= 3)
       ff = true;
  }

  if (f >= 2 || ff) {
    int c = 0;
    int fff = true;
    for (int i=0; i<2222; ++i) {
      if (v[i].size() >= 3) {
        ans [0][c]   = v[i][0];
        ans [0][c+1] = v[i][1];
        ans [0][c+2] = v[i][2];

        ans [1][c]   = v[i][2];
        ans [1][c+1] = v[i][1];
        ans [1][c+2] = v[i][0];

        ans[2][c]   = v[i][1];
        ans[2][c+1] = v[i][0];
        ans[2][c+2] = v[i][2];

        c += 3;
        for (int j = 3; j<v[i].size(); ++j) {
          ans[0][c] = ans[1][c] = ans[2][c] = v[i][j];
          c++;
        }
      }
      else if (v[i].size() == 2) {
        if (fff) {
          ans [0][c] = v[i][0];
          ans [0][c+1] = v[i][1];

          ans [1][c] = v[i][1];
          ans [1][c+1] = v[i][0];

          ans[2][c] = v[i][0];
          ans[2][c+1] = v[i][1];
          c++; c++;
          fff = !fff;
        }
        else {
          ans [0][c] = v[i][0];
          ans [0][c+1] = v[i][1];

          ans [1][c] = v[i][1];
          ans [1][c+1] = v[i][0];

          ans[2][c] = v[i][1];
          ans[2][c+1] = v[i][0];
          c++; c++;
          fff = !fff;
        }
      }
      else if(v[i].size() == 1) {
        ans[0][c] = v[i][0];
        ans[1][c] = v[i][0];
        ans[2][c] = v[i][0];
        c++;
      }
    }

    cout << "YES" << endl;
    for (int i=0; i<3; ++i) {
      for (int j=0; j<n; ++j)
        cout << ans[i][j] << " ";
      cout << endl;
    }

  }
  else {
    cout << "NO";
  }

  return 0;
}