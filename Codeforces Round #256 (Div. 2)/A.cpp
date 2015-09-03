// http://codeforces.com/contest/448/problem/A

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
  int n;

  int cups=0, medals=0;
  for (int i=0; i<6; ++i){
    int t;
    cin >> t;
    if (i<=2)
      cups += t;
    else
      medals += t;
  }

  cin >> n;

  vector<int> v(n,0);
  int i = 0;
  for ( ; i<n && medals; ++i){
    while (v[i] < 10 && medals) {
      v[i] ++;
      medals --;
    }
  }

  for ( ; i<n && cups; ++i){
    while (v[i] < 5 && cups) {
      v[i] ++;
      cups --;
    }
  }

  if (cups || medals)
    cout << "NO";
  else
    cout << "YES";

  return 0;
}