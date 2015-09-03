// http://codeforces.com/contest/143/problem/B

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
  string s;
  cin >> s;

  int punto = false;
  int signo = false;
  string entera;
  string fracion;

  if (s[0] == '-') {
    s = s.substr(1);
    signo = true;
  }

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      punto = true;
      int cnt = 0;
      for (int j = i + 1; j < s.size() && cnt < 2; ++j) {
        fracion += toStr(s[j]);
        cnt ++;
      }
      break;
    }
    entera += toStr(s[i]);
  }

  string entera2;
  int cnt = 1;
  for (int i = entera.size() - 1; i >= 0; --i) {
    entera2 = toStr(entera[i]) + entera2;
    if (cnt % 3 == 0) entera2 = "," + entera2;
    cnt ++;
  }

  while (fracion.size() < 2) fracion += "0";
  if (entera2[0] == ',') entera2 = entera2.substr(1);

  if (signo) cout << "(";
  cout << "$";
  cout << entera2;
  cout << "." << fracion;
  if (signo) cout << ")";

  return 0;
}