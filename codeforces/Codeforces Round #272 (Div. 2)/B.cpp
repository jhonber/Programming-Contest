// http://codeforces.com/contest/476/problem/B

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

string s2;
int pos = 0;
int tot = 0;

int f(int i, int p) {
  if (i > s2.size()) return 0;
  if (i == s2.size()) tot ++;
  if (i == s2.size() && p == pos) return 1;
  int ans = 0;
  if (s2[i] == '?') {
    ans += f(i + 1, p + 1);
    ans += f(i + 1, p - 1);
  }
  else if (s2[i] == '+')
    ans += f(i + 1, p + 1);
  else
    ans += f(i + 1, p - 1);

  return ans;
}

int main(){ __
  string s1;
  cin >> s1 >> s2;

  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == '+') pos ++;
    else pos --;
  }

  double good = f(0,0);
  cout.precision(9);
  cout << good / tot;

  return 0;
}