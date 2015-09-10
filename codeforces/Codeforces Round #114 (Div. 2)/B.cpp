// http://codeforces.com/contest/168/problem/B

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
  string line;

  int cnt = 0;
  vector<int> amp;
  vector<string> ans;
  while (getline(cin, line)) {
    if (line[0] == '\t') continue;
    int f = false;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] != ' ' and line[i] == '#') {
        f = true; break;
      }
      else if (line[i] != ' ' and line[i] != '#') break;
    }

    if (f) {
      ans.push_back(line);
      amp.push_back(1);
      cnt ++;
    }
    else {
      stringstream ss;
      ss << line;
      string token;
      string res;
      while (ss >> token) res += token;
      ans.push_back(res);
      amp.push_back(0);
    }
  }

  int f;
  int tot = ans.size();
  int i = 0;
  while (i < tot) {
    f = false;
    cout << ans[i];
    if (amp[i]) {cout << endl; f = true; }
    else if (!amp[i] and i + 1 and amp[i + 1]) {cout << endl; f = true; }
    i ++;
  }

  if (!f) cout << endl;

  return 0;
}
