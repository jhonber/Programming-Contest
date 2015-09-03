// http://codeforces.com/contest/471/problem/A

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

  vector<int> v;

  for (int i=0; i<6; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  int legs = 0;
  for (int i=1; i<=9; ++i) {
    int t = 0;
    for (int j=0; j<6; ++j) {
      if (v[j] == i) {
        t ++;

        if (t == 4) {
          legs = i;
          int c = 4;
          for (int j=0; j<6 && c > 0; ++j) {
            if (v[j] == i) {
              v[j] = 0;
              c --;
            }
          }
          break;
        }
      }
    }
  }

  int ele = 0;
  for (int i=1; i<=9; ++i) {
    int t = 0;
    for (int j=0; j<6; ++j) {
      if (v[j] == i)
        t ++;
    }
    if (t == 2) {
      ele = i;
      break;
    }
  }

  if (legs && ele)
    cout << "Elephant";
  else if (legs)
    cout << "Bear";
  else cout << "Alien";

  return 0;
}