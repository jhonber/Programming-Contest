// http://codeforces.com/contest/486/problem/C

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

char next (char c, int op) {
  int t = c - 'a';
  if (op > 0) t += 1;
  else t -= 1;

  if (t < 0) t += 26;
  else t %= 26;

  return char(t + 'a');
}

int near (char a, char b) {
  int c1 = 0, c2 = 0;
  char t = a;
  while (true) {
    t = next(t,1);
    c1 ++;
    if (t == b) break;
  }

  char t2 = a;
  while (true) {
    t2 = next(t2,-1);
    c2 ++;
    if (t2 == b) break;
  }
  return min(c1,c2);
}

int solve (string &s, int p, int n) {
  int mid = n / 2 - 1;
  int ans = 0;

  if ( p > mid ) {
    int l,r;
    vector<int> pos;
    for (int i = mid + 1; i < n; ++i) {
      if (s[i] != s[n - i - 1]) {
        pos.push_back(i);
        ans += near(s[i],s[n - i - 1]);
      }
    }
    if (pos.size() > 0) {
      sort(all(pos));
      l = pos[0]; r = pos[pos.size()-1];
      int t = r - l;
      ans += min( abs(p - l), abs(p - r) ) + t;
    }
  }
  else {
    int l,r;
    vector<int> pos;
    for (int i = mid; i >= 0; --i) {
      if (s[i] != s[n - i - 1]) {
        pos.push_back(i);
        ans += near(s[i],s[n - i - 1]);
      }
    }
    if (pos.size() > 0) {
      sort(all(pos));
      l = pos[0]; r = pos[pos.size()-1];
      int t = r - l;
      ans += min( abs(p - l), abs(p - r) ) + t;
    }
  }

  return ans;
}

int main(){ __
  int n,p;
  cin >> n >> p;

  string s;
  cin >> s;
  p --;
  cout << solve(s,p,n);

  return 0;
}