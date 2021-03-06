// http://codeforces.com/contest/469/problem/C

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

int main(){ __
  int n;
  cin >> n;

  if (n < 4)
    cout << "NO";
  else {
    cout << "YES" << endl;

    if (n==4)
      cout << "4 * 3 = 12" << endl << "12 * 1 = 12" << endl << "12 * 2 = 24" << endl;
    else if (n == 5)
      cout << "4 * 5 = 20" << endl << "3 + 2 = 5" << endl << "5 - 1 = 4" << endl << "20 + 4 = 24" << endl;
    else {
      cout << "1 - 3 = -2" << endl << "-2 + 2 = 0" << endl;
      for (int i=5; i<= n; ++i) {
        if (i != 6) {
          cout << "0 * " << i << " = 0" << endl;
        }
      }
      cout << "6 + 0 = 6" << endl << "6 * 4 = 24" << endl;
    }
  }

  return 0;
}