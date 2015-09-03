// http://codeforces.com/contest/120/problem/A

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

  #ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  string in;
  cin >> in;

  int rail;
  cin >> rail;

  if (in == "front" && rail == 1){
    cout << "L";
  }
  else if (in == "front" && rail == 2){
    cout << "R";
  }
  else if (in == "back" && rail == 1){
    cout << "R";
  }
  else if (in == "back" && rail == 2){
    cout << "L";
  }

  return 0;
}
