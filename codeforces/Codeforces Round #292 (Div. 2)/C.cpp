// http://codeforces.com/contest/515/problem/C

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

#define pb push_back

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7') ans.pb(toInt(s[i]));
    else if (s[i] == '4') {
      ans.pb(3); ans.pb(2); ans.pb(2);
    }
    else if (s[i] == '6') {
      ans.pb(5); ans.pb(3);
    }
    else if (s[i] == '8') {
      ans.pb(7); ans.pb(2); ans.pb(2); ans.pb(2);
    }
    else if (s[i] == '9') {
      ans.pb(7); ans.pb(3); ans.pb(3); ans.pb(2);
    }
  }

  sort(all(ans));
  reverse(all(ans));

  for (int i = 0; i < ans.size(); ++i) cout << ans[i];

  return 0;
}