// http://codeforces.com/contest/251/problem/A

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
  int n,d;
  cin >> n >> d;

  vector<int> v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i];

  long long ans = 0;
  vector<int> :: iterator pos;
  int k = 0;

  int ant = 0;
  for (int i=0; i<n-2; ++i) {
    pos = lower_bound(v.begin()+i,v.end(),d+v[i]);
    if (pos != v.end() && (*pos - v[i]) > d)
      pos --;

    k = (int)(pos-v.begin()) - i + 1;
    if (k<3) continue;
    if (pos == v.end()) k--;
    ans += ((k-0LL)*(k-1LL)*(k-2LL)) / 6;

    if (ant - i + 1 > 2)
      ans -= (((ant-i+1)-0LL)*((ant-i+1)-1LL)*((ant-i+1)-2LL)) / 6;

    ant = pos-v.begin();
    if (pos == v.end() || pos - v.begin() == n-1)
      break;
  }

  cout << ans;
  return 0;
}