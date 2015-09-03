// http://codeforces.com/contest/166/problem/A

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

bool comp(pair<int,int> i, pair<int,int> j){
  if (i.first==j.first){
    return i.second < j.second;
  }
  return i.first>j.first;
}

int main(){ __
  int n,k;
  cin >> n >> k;

  k--;
  vector< pair<int,int> > v(n);
  for (int i=0; i<n; ++i){
    cin >> v[i].first;
    cin >> v[i].second;
  }

  sort(all(v),comp);

  int ans = 0;
  for (int i=0; i<n; ++i){
    if (v[k].first == v[i].first && v[k].second == v[i].second )
      ans ++;
  }

  cout << ans;

  return 0;
}