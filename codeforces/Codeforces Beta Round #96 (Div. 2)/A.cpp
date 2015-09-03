// http://codeforces.com/contest/133/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;
#define MN 4004

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

bool check(string s){
  for(int i=0; i<s.size(); ++i)
    if(s[i]=='H' || s[i] == 'Q' || s[i] == '9')
      return true;
  return false;
}

int main(){
  string s;
  cin >> s;

  if( check(s) )
    cout << "YES";
  else cout << "NO";

  return 0;
}