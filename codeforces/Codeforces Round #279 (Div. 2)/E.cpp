// http://codeforces.com/contest/490/problem/E

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

int pos;

int check(string &ant, string &cur) {
  for (int i = 0; i < ant.size(); ++i) if (cur[i] != '?') {
    int a = cur[i] - '0';
    int b = ant[i] - '0';
    pos = i;
    if (a > b) return 1;
    if (a < b) return 2;
  }
  return 0;
}

void minimize(string &s) {
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '?') s[i] = i ? '0' : '1';
}

int main(){ __
  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  minimize(v[0]);
  for (int i = 1; i < n; ++i) {
    int s1 = v[i].size();
    int s2 = v[i - 1].size();
    if (s1 < s2) {
      cout << "NO";
      return 0;
    }

    if (s1 > s2) minimize(v[i]);
    else {
      int res = check (v[i - 1], v[i]);
      if (res == 0) {
        pos = 0;
        for (int j = s1 - 1 ; j >= 0; --j) {
          if (v[i][j] == '?' && (int)v[i - 1][j] - '0' < 9 ) {
            v[i][j] = char( ((int)v[i - 1][j] - '0') + 1 ) + '0';
            pos = j;
            break;
          }
        }
        for (int j = 0; j < pos; ++j) if (v[i][j] == '?') v[i][j] = v[i - 1][j];
        for (int j = 0; j < s1; ++j) if (v[i][j] == '?') v[i][j] = '0';
      }
      else if(res == 1) {
        for (int j = pos; j < s1; ++j) if (v[i][j] == '?') v[i][j] = '0';
        for (int j = 0; j < s1; ++j) if (v[i][j] == '?') v[i][j] = v[i - 1][j];
      }
      else {
        int j = pos;
        for ( ; j >= 0; --j) {
          if (v[i][j] == '?' && (int)v[i - 1][j] - '0' < 9 ) {
            v[i][j] = char( ((int)v[i - 1][j] - '0') + 1 ) + '0';
            break;
          }
        }
        for ( ; j < s1; ++j) if (v[i][j] == '?') v[i][j] = '0';
        for (int j = 0; j < s1; ++j) if (v[i][j] == '?') v[i][j] = v[i - 1][j];
      }
    }

    if (toInt(v[i]) <= toInt(v[i - 1])) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i)
    cout << v[i] << endl;

  return 0;
}