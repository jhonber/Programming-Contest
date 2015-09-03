// http://codeforces.com/contest/278/problem/B

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

string bfs(set<string> &subs) {
  deque<string> Q;
  for (int i = 0; i < 26; ++i) {
    string c = toStr(char(i + 'a'));
    Q.push_back(c);
  }

  while (true) {
    string cur = Q.front(); Q.pop_front();

    if (subs.count(cur) == 0) return cur;

    for (int i = 0; i < 26; ++i) {
      string c = toStr(char(i + 'a'));
      Q.push_back(cur + c);
    }
  }
}


int main() {
  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  set<string> subs;
  for (int i = 0; i < n; ++i) {
    int t = v[i].size();
    subs.insert(v[i]);
    for (int j = 0; j < t; ++j) {
      for (int k = 0; k < t; ++k) {
        string sub = v[i].substr(j,k);
        if (sub.size()) subs.insert(sub);
      }
    }
  }

  cout << bfs(subs);
  return 0;
}