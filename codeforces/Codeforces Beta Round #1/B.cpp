// http://codeforces.com/contest/1/problem/B

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

const int mx = 1000000;
vector<string> mp(mx + 100);

void gen (string s, int i, int c) {
  while (true) {
    mp[c] = s;
    if (c >= mx) return;

    for (int x = i; x >= 0; --x) {
      if (s[x] == 'Z') {
        s[x] = 'A';
        if (!x) {
          s = "A" + s;
          i = s.size() - 1;
        }
      }
      else {
        s[x] ++;
        break;
      }
    }
    c ++;
  }
}

bool isLetter(char c) {
  if (c >= 'A' and c <= 'Z') return true;
  return false;
}

long long pot (int a, int b) {
  long long p = 1;
  while (b --> 0) {
    p *= a;
  }
  return p;
}

long long f (string s) {
  long long ans = 0;
  for (int i = s.size() - 1, j = 0; i >= 0; --i, ++j) {
    ans += ((s[i] - 'A') + 1) * pot(26, j);
  }
  return ans;
}

int main() {
  gen ("A", 0, 1);

  int n;
  cin >> n;

  while (n --> 0) {
    char in[50];
    scanf("%s", &in);

    int a = 0, b = 0;
    sscanf(in, "R%dC%d", &a, &b);

    if (!a or !b) {
      string code;
      string num;
      int t = strlen(in);

      for (int i = 0; i < t; ++i) {
        if (isLetter(in[i])) code += toStr(in[i]);
        else num += toStr(in[i]);
      }
      cout << "R" << num << "C" << f(code) << endl;
    }
    else cout << mp[b] << a << endl;
  }

  return 0;
}