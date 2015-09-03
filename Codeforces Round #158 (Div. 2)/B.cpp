// http://codeforces.com/contest/260/problem/B

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

int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
set<string> allDates;

void gen() {
  for (int j = 2013; j <= 2015; ++j) {
    string y = toStr(j);
    for (int i = 0; i < 12; ++i) {
      string m = toStr(i + 1);
      if (m.size() < 2) m = "0" + m;
      for (int k = 1; k <= days[i]; ++k) {
        string d = toStr(k);
        if (d.size() < 2) d = "0" + d;
        allDates.insert(d + "-" + m + "-" + y);
      }
    }
  }
}


int main() {
  string s;
  cin >> s;

  gen();
  map<string, int> ans;
  for (int i = 0; i < s.size(); ++i) {
    string sub = s.substr(i, 10);
    if (allDates.count(sub) > 0) {
      ans[sub] ++;
    }
  }

  string ss;
  int cnt = 0;
  foreach(x, ans) {
    if (x->second > cnt) {
      ss = x->first;
      cnt = x->second;
    }
  }

  cout << ss;

  return 0;
}