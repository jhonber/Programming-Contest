// http://codeforces.com/contest/242/problem/B

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

struct seg {
  int size;
  int left;
  int rigth;
  int pos;
};

bool comp(seg i, seg j) {
  return i.size > j.size;
}

int main() {
  int n;
  cin >> n;

  vector<seg> v(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    seg sg;
    sg.left = l;
    sg.rigth = r;
    sg.size = (r - l) + 1;
    sg.pos = i + 1;

    v[i] = sg;
  }

  sort(all(v), comp);

  for (int i = 1; i < n; ++i) {
    if (v[i].left < v[0].left || v[i].rigth < v[0].left || v[i].rigth > v[0].rigth || v[i].left > v[0].rigth) {
      cout << -1;
      return 0;
    }
  }

  cout << v[0].pos;
  return 0;
}