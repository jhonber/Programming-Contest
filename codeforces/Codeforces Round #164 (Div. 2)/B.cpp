// http://codeforces.com/contest/268/problem/B

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

  if (n==2) {
    cout << 3;
    return 0;
  }

  vector<int> v(n);
  v[n-1] = n;
  v[n-2] = n-1;
  v[n-3] = n-1;

  int k = 1;
  for (int i=n-4; i>=0; --i)
    v[i] = v[i+1] + k++;

  int ans = 0;
  for (int i=0; i<n; ++i)
    ans += v[i];

  cout << ans;

  return 0;
}