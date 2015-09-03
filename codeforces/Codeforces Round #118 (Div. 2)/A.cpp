// http://codeforces.com/contest/186/problem/A

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
  string a,b;
  cin >> a >> b;

  if (a.size() != b.size()){
    cout << "NO";
  }
  else {
    int dif = 0;
    int pos1 = -1;
    int pos2 = -1;

    for (int i=0; i<a.size(); ++i){
      if (a[i] != b[i]){
        dif ++;
        if (pos1 == -1)
          pos1 = i;
        else if (pos2 == -1)
          pos2 = i;
      }
    }

    if(dif == 2){
      swap(a[pos1],a[pos2]);
      if (a==b)
        cout << "YES";
      else
        cout << "NO";
    }
    else cout << "NO";
  }
  return 0;
}
