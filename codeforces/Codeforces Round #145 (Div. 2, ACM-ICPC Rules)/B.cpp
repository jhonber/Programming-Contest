// http://codeforces.com/contest/234/problem/B

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
  #ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,k;
  cin >> n >> k;

  vector< pair<int,int> > v(n);
  for (int i=0; i<n; ++i){
    cin >> v[i].first;
    v[i].second = i+1;
  }

  sort(all(v));

  int mmin = INT_MAX;
  vector<int> ans;
  for (int i=n-1; i>=n-k; --i){
    mmin = min(mmin,v[i].first);
    ans.push_back(v[i].second);
  }

  sort(all(ans));
  cout << mmin << endl;
  for (int i=0; i<k; ++i)
    cout << ans[i] << " ";

  return 0;
}