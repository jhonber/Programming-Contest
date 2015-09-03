// http://codeforces.com/contest/131/problem/A

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

bool is(char c){
  if (c>='a' && c<='z')
    return true;
  return false;
}

int main(){ __
  string s;
  cin >> s;

  int c = 0;

  for (int i=0; i<s.size(); ++i){
    if ( !is(s[i]) )
      c++;
  }

  if (c == s.size() || ( is(s[0]) && c == s.size()-1)){
    for (int i=0; i<s.size(); ++i){
      if ( is(s[i]) )
        cout << (char)toupper(s[i]);
      else
        cout << (char)tolower(s[i]);
    }
  }
  else
    cout << s;

  return 0;
}