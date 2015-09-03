// http://codeforces.com/contest/462/problem/C

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

bool comp(int i, int j) {
  return i>j;
}

int main(){ __
  int n;
  cin >> n;

  long long v[n];
  for (int i=0; i<n; ++i) {
    cin >> v[i];
  }

  sort(v,v+n,comp);

  long long image[n];

  image[0] = v[0];
  for (int i=1; i<n; ++i)
    image[i] = image[i-1] + v[i];

  long long ans = image[0];
  for (int i=1; i<n; ++i) {
    ans += image[i] + v[i];
  }

  cout << ans;


  return 0;
}