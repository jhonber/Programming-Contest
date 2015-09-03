// http://codeforces.com/contest/78/problem/A

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

bool is_vowel(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
  string a,b,c;

  getline(cin,a);
  getline(cin,b);
  getline(cin,c);

  int aa = 0, bb = 0, cc = 0;
  for(int i=0; i<a.size(); ++i){
    if(is_vowel(a[i]))
      aa++;
  }

  for(int i=0; i<b.size(); ++i){
    if(is_vowel(b[i]))
      bb++;
  }

  for(int i=0; i<c.size(); ++i){
    if(is_vowel(c[i]))
      cc++;
  }

  if(aa == 5 && bb==7 && cc==5)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}