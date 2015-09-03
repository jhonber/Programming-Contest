// http://codeforces.com/contest/465/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int getIndex(string s) {
  for (int i = 1; i < s.size(); ++i) {
    if (s[i - 1] == s[i]) return i;
    if (i + 1 < s.size() && s[i - 1] == s[i + 1]) return i + 1;
  }
  return s.size() - 1;
}

char getNext(string s, int &p, int i, int f) {
  char res = '*';
  int j;

  if (f == -1) j = 0;
  else j = (s[i] - 'a') + 1;

  for ( ;j < p ; ++j) {
    char c = j + 'a';
    if ((i - 1 >= 0 && c != s[i - 1]) && (i - 2 >= 0 && c != s[i - 2] )) return c;
    else if (i == 1 && c != s[i - 1]) return c;
    else if (!i) return c;
  }
  return res;
}

int main(){ __
  int n,p;
  string s,s2;

  cin >> n >> p >> s;

  int ind = getIndex(s);

  for (int i = ind; i >= 0; --i) {
    s2 = s;
    char c = getNext(s,p,i,0);
    if (c != '*') {
      s2[i] = c;
      int f = true;
      for (int j = i + 1; j < s.size(); ++j) {
        c = getNext(s2,p,j,-1);
        if (c == '*') {
          f = false;
          break;
        }
        s2[j] = c;
      }
      if (f) {
        cout << s2;
        return 0;
      }
    }
  }

  cout << "NO";

  return 0;
}