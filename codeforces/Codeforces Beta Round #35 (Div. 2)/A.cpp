// http://codeforces.com/contest/35/problem/A

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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int x;
  cin >> x; x--;

  vector<int> v(3,0);
  v[x] = true;
  int a,b;
  for (int i = 0; i < 3; ++i) {
    cin >> a >> b; a--; b--;

    swap(v[a],v[b]);
  }

  for (int i = 0; i < 3; ++i) if (v[i] == true) {
    cout << i + 1;
    return 0;
  }
}