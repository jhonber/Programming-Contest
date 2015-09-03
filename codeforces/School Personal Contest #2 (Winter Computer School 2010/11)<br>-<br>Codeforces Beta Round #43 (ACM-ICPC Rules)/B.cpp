// http://codeforces.com/contest/46/problem/B

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

int main(){ __
  map<string,int> mapa;
  mapa["S"] = 0;
  mapa["M"] = 1;
  mapa["L"] = 2;
  mapa["XL"] = 3;
  mapa["XXL"] = 4;


  map<int,string> mapa2;
  mapa2[0] = "S";
  mapa2[1] = "M";
  mapa2[2] = "L";
  mapa2[3] = "XL";
  mapa2[4] = "XXL";

  vector<int> v(5);
  for (int i = 0; i < 5; ++i)
    cin >> v[i];

  int k;
  cin >> k;

  string ts;
  for (int i = 0; i < k; ++i) {
    cin >> ts;
    int x = mapa[ts];
    vector<int> vv;

    if (x == 0)
      vv = { x, x + 1, x + 2 , x + 3, x + 4 };
    else if (x == 1)
      vv = { x, x + 1, x - 1 , x + 2, x + 3 };
    else if (x == 2)
      vv = { x, x + 1, x - 1 , x + 2, x - 2 };
    else if (x == 3)
      vv = { x, x + 1, x - 1 , x - 2, x - 3 };
    else if (x == 4)
      vv = { x, x - 1, x - 2 , x - 3, x - 4 };


    for (int j = 0 ; j < 5; ++j) {
      if ( vv[j] >= 0 && vv[j] < 5 && v[vv[j]]) {
        cout << mapa2[vv[j]] << endl;
        v[vv[j]] --;
        break;
      }
    }
  }

  return 0;
}