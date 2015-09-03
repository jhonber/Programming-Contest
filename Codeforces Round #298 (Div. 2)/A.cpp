// http://codeforces.com/contest/534/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  int n;
  cin >> n;

  if (n <= 2) {
    cout << 1 << endl;
    cout << 1;
    return 0;
  }

  if (n == 3) {
    cout << 2 << endl;
    cout << "1 3";
    return 0;
  }

  if (n == 4) {
    cout << 4 << endl;
    cout << "2 4 1 3";
    return 0;
  }

  vector<int> v;
  for (int i = 1; i <= n; i+= 2) v.push_back(i);
  for (int i = 2; i <= n; i+= 2) v.push_back(i);

  cout << v.size() << endl;
  for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";

  return 0;
}