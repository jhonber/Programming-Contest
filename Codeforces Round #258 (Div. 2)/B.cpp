// http://codeforces.com/contest/451/problem/B

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
  vector<int> vv(n);

  for (int i=0; i<n; ++i)
    cin >> v[i];

  vv = v;
  sort(all(vv));

  int a=0,b=0;
  for (int i=0; i<n; ++i){
    if (v[i] != vv[i]){
      a = i;
      for (int j=i; j<n-1; ++j){
        if (v[j] < v[j+1]){
          b = j+1;
          break;
        }
      }
      if (!b) b = n;
      break;
    }
  }

  reverse(v.begin()+a,v.begin()+b);
  for (int i=0; i<n; ++i){
    if (v[i]!=vv[i]){
      cout << "no";
      return 0;
    }
  }

  cout << "yes" << endl << a+1 << " " << ( b==0 ? 1 : b);

  return 0;
}