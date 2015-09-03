// http://codeforces.com/contest/122/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

bool f(int n){

  while(n){
    if(n%10 != 4 && n%10 != 7 )
      return false;
    n /= 10;
  }

  return true;
}

bool check(int n){
  for(int i=2; i<=n; ++i){
    if(n%i==0 && f(i))
      return true;
  }
  return false;
}

int main(){
  int n;
  cin >> n;

  if( check(n) ) cout << "YES";
  else cout << "NO";

  return 0;
}