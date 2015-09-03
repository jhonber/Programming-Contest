// http://codeforces.com/contest/133/problem/B

#include<bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x ' = ' << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};


int main(){ __
  string s;
  cin >> s;

  map <char,string> mapa;
  mapa['>']="1000";

  mapa['<']="1001";

  mapa['+']="1010";

  mapa['-']="1011";

  mapa['.']="1100";

  mapa[',']="1101";

  mapa['[']="1110";

  mapa[']']="1111";


  string res = "";
  for (int i=0; i<s.size(); ++i)
    res += mapa[s[i]];

  long long M = 1000003;
  long long ans = 0;
  long long tmp = 1;

  for (int i=res.size()-1; i>=0; --i){
    if (res[i]=='1')
      ans += tmp;
    ans %= M;
    tmp *= 2;
    tmp %= M;
  }

  cout << ans;

  return 0;
}
