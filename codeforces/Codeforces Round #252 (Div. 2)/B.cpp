// http://codeforces.com/contest/441/problem/B

#include<bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class t> string tostr(const t &x)
{ stringstream s; s << x; return s.str(); }

template <class t> int toint(const t &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

const int MAX = 3333;

int main(){__
  int n,v,a,b;
  cin >> n >> v;

  vector<int> vv[MAX];
  memset(vv, 0, sizeof vv);

  for (int i=0; i<n; ++i){
    cin >> a >> b;
    vv[a].push_back(b);
  }

  int ans = 0;
  for (int i=1; i<MAX; ++i){
    int c = 0;
    for(int j=0; j<vv[i-1].size(); ++j){
      while(vv[i-1][j] > 0 && c < v){
        ans ++; c++;
        vv[i-1][j] --;
      }
    }

    for(int j=0; j<vv[i].size(); ++j){
      while(vv[i][j] > 0 && c < v){
        ans ++; c++;
        vv[i][j] --;
      }
    }
  }

  cout << ans;

  return 0;
}