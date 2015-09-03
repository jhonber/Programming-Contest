// http://codeforces.com/contest/558/problem/A

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

  vector< pair<int,int> > v(n + 1);
  for (int i = 0; i < n; ++i){
    int a,b;
    cin >> a >> b;
    v[i] = make_pair(a,b);
  }

  v.push_back(make_pair(0,0));

  sort(all(v));

  int pos = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (v[i].first == 0 and v[i].second == 0) {
      pos = i;
      break;
    }
  }

//  for (int i = 0; i < n + 1; ++i) cout << v[i].first << " " << v[i].second << endl;

  int pos2 = pos;
  vector< pair<int,int> > v2;
  v2 = v;
  int ans = 0;
  int f = true;
  while (true) {
    if (f) pos --;
    else pos ++;

    if (pos < 0 or pos > n + 1) break;

    if (v[pos].second > 0) {
      ans += v[pos].second;
      f = !f;
      v[pos].second = 0;
    }
  }

  v = v2;
  pos = pos2;
  int ans2 = 0;
  f = false;
  while (true) {
    if (f) pos --;
    else pos ++;

    if (pos < 0 or pos > n + 1) break;
    if (v[pos].second > 0) {
      ans2 += v[pos].second;
      f = !f;
      v[pos].second = 0;
    }
  }

  cout << max(ans, ans2);


  return 0;
}