// http://codeforces.com/contest/411/problem/A

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

bool upp(string s) {
  for (int i=0; i<s.size(); ++i)
    if (s[i] >= 'A' && s[i] <= 'Z')
      return true;

  return false;
}

bool loww(string s) {
  for (int i=0; i<s.size(); ++i)
    if (s[i] >= 'a' && s[i] <= 'z')
      return true;

  return false;
}

bool digg(string s) {
  for (int i=0; i<s.size(); ++i)
    if (isdigit(s[i]))
      return true;

  return false;
}


int main(){ __
  string s;
  cin >> s;

  if (s.size()>=5 && upp(s) && loww(s) && digg(s))
    cout << "Correct";
  else
    cout << "Too weak";
  return 0;
}