// http://codeforces.com/contest/436/problem/A

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

int x,x2;
vector< pair<int,int> > v,vv;

int solve(int f) {
  priority_queue<int> Q1,Q2;
  x = x2;

  int i=0, j=0;
  for ( ; i<v.size(); ++i)
    if (v[i].first <= x) Q1.push(v[i].second);
    else break;

  for ( ; j<vv.size(); ++j)
    if (vv[j].first <= x) Q2.push(vv[j].second);
    else break;

  int ans = 0;
  while (!Q1.empty() || !Q2.empty()) {
    if (f) {
      if (Q1.empty()) break;
      int t = Q1.top(); Q1.pop();
      ans ++;
      x += t;
      f = !f;
    }
    else if (!Q2.empty()){
      if (Q2.empty()) break;
      int t = Q2.top(); Q2.pop();
      ans ++;
      x += t;
      f = !f;
    }
    else break;


    for ( ; i<v.size(); ++i)
      if (v[i].first <= x) Q1.push(v[i].second);
      else break;

    for ( ; j<vv.size(); ++j)
      if (vv[j].first <= x) Q2.push(vv[j].second);
      else break;
  }

  return ans;
}

int main(){ __
  int n,t,h,m;
  cin >> n >> x;

  for (int i=0; i<n; ++i) {
    cin >> t >> h >> m;
    if (t) v.push_back(make_pair(h,m));
    else vv.push_back(make_pair(h,m));
  }

  x2 = x;

  sort(all(v));
  sort(all(vv));

  cout << max(solve(0),solve(1));

  return 0;
}