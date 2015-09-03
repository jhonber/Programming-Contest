// http://codeforces.com/contest/208/problem/A

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
  string s;
  getline(cin,s);

  for (int i=0; i<s.size(); ++i) {
    if (s.substr(i,3) == "WUB")
      s[i] = s[i+1] = s[i+2] = '*';
    if (s[i]==' ') s[i] = '*';
  }

  int j = s.size()-1;
  for ( ; j>=0; --j){
    if (s[j]=='*')
      s[j] = '+';
    else break;
  }

  int i=0;
  while (i<s.size()){
    while (s[i] == '*') i++;
    while ((s[i] != '*' || s[i]==' ') && i<=j) {
      cout << s[i];
      i ++;
    }
    i ++;
    cout << " ";
  }

  return 0;
}