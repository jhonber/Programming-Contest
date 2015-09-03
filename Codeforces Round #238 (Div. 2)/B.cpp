// http://codeforces.com/contest/405/problem/B

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

  vector<char> v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i];

  int ans = 0;
  for (int i=0; i<n; ++i){
    if (v[i] == 'R'){
      v[i] = '*';
      int t = i;
      int c = 1;

      while ( i<n && v[i]!='L'){
        c++;
        v[i] = '*';
        i++;
      }

      if(v[i]=='L'){
        v[i] = '*';
      if (c%2 == 1){
        ans ++;
      }
      }
    }
  }

  for (int i=n-1; i>=0; --i){
    if (v[i]=='L'){
      v[i] = '.';
      while (v[i]=='.'){
        v[i] = '*';
        --i;
      }
    }
  }

  for (int i=0; i<n; ++i){
    if (v[i] == '.')
      ans++;
  }

  cout << ans;
  return 0;
}