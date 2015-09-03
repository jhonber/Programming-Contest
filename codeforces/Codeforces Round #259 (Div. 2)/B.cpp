// http://codeforces.com/contest/454/problem/B

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

  vector<int> v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i];

  int f = true;
  for (int i=1; i<n; ++i){
    if (v[i-1]>v[i]){
      f = false;
      break;
    }
  }

  if (f){
    cout << 0;
  }
  else {
    for (int i=1; i<n; ++i){
      if (v[i-1] > v[i]){
        int pos = i;
        int f = true;
        for (int j=0; j<n-1; ++i,++j){
          if (v[i%n] > v[(i+1)%n]){
            f = false;
            break;
          }
        }
        if (f) cout << n-pos;
        else cout << -1;
        return 0;
      }
    }
  }

  return 0;
}
