// http://codeforces.com/contest/92/problem/B

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
  string n,n2;
  cin >> n;

  n2 = n;
  int ans = 0;
  int ind = n.size()-1;
  int carry = false;

  while (ind>=0){
    if (carry && n[ind]=='1')
      n[ind] = '0';
    else if (carry && n[ind]=='0'){
      n[ind] = '1';
      carry = false;
    }

    if (n[ind] == '0'){
      ans ++;
      ind --;
    }
    else {
      ans += 2;
      ind --;
      carry = true;
    }
  }

  // My code is so crazy :S here some stuff are random
  int crazy = 0;
  for (int i=0;i<n2.size();++i)
    if (n2[i]=='1') crazy++;

  if (crazy==1) ans -= 2;
//  else if (crazy==n2.size())
//    ans += 2;

  cout << ans;

  return 0;
}
