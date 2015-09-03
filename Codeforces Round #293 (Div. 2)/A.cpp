// http://codeforces.com/contest/518/problem/A

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

bool check(string &s, string &t) {
  return s < t;
}

string next(string &s, string &t) {
  for (int i = s.size() - 1; i >= 0; --i) {
    string tmp = s;
    for (int k = (tmp[i] - 'a') + 1; k < 26; ++k) {
      tmp[i] = k + 'a';
      if (check(tmp,t)) return tmp;
      for (int j = i + 1; j < s.size(); ++j) {
        tmp[j] = 'a';
      }
      if (check(tmp,t)) return tmp;
      string tmp2 = tmp;
      for (int j = s.size() - 1; j > k; --j) {
        tmp = tmp2;
        for (int l = (tmp[j] - 'a') + 1; l < 26; ++l) {
          tmp[j] = l + 'a';
          if (check(tmp,t)) return tmp;
        }
      }
    }
  }
  return "paila";
}

int main() {

  string s,t;
  cin >> s >> t;

  string ans = next(s,t);
  if (ans == "paila") cout << "No such string";
  else cout << ans;

  return 0;
}