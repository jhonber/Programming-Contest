// http://codeforces.com/contest/550/problem/C

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
  string n;
  cin >> n;

  int t = n.size();
  for (int i = 0; i < t; ++i) if (toInt(n[i]) % 8 == 0) {
    cout << "YES" << endl << n[i];
    return 0;
  }

  for (int i = 0; i < t; ++i) {
    for (int j = i + 1; j < t; ++j) {
      int num = toInt( toStr(n[i]) + toStr(n[j]) );
      if (num % 8 == 0) {
        cout << "YES" << endl << num;
        return 0;
      }
    }
  }

  for (int i = 0; i < t; ++i) {
    for (int j = i + 1; j < t; ++j) {
      for (int k = j + 1; k < t; ++k) {
        int num = toInt( toStr(n[i]) + toStr(n[j]) + toStr(n[k]) );
        if (num % 8 == 0) {
          cout << "YES" << endl << num;
          return 0;
        }
      }
    }
  }

  cout << "NO";
  return 0;
}