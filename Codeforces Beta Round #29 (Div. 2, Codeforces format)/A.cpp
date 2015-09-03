// http://codeforces.com/contest/29/problem/A

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

  int x,d;
  vector< pair<int, int> > pos(n);

  for (int i = 0; i < n; ++i) {
    cin >> x >> d;
    pos[i] = make_pair(x, d);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i != j and pos[j].first + pos[j].second == pos[i].first and pos[i].first + pos[i].second == pos[j].first) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
  return 0;
}