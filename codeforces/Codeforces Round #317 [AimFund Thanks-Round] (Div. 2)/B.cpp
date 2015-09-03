// http://codeforces.com/contest/572/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  int n, s;
  cin >> n >> s;

  map<int, int> sell;
  map<int, int> buy;

  char d;
  int p, q;
  for (int i = 0; i < n; ++i) {
    cin >> d >> p >> q;
    if (d == 'S') sell[p] += q;
    else buy[p] += q;
  }

  vector< pair<int, pair<int,int> > > v;
  vector< pair<int, pair<int,int> > > vv;

  foreach(x, sell) {
    int tot = x->first;
    v.push_back(make_pair(tot, make_pair(x->first, x->second)));
  }

  foreach(x, buy) {
    int tot = x->first;
    vv.push_back(make_pair(tot, make_pair(x->first, x->second)));
  }

  sort(all(v));
  sort(all(vv));

  vector<string> ans;

  int tot = s;
/*  for (int i = s - 1; i >= 0 and v.size() > 0 and tot --> 0; --i) {
    cout << "S " << v[i].second.first << " " << v[i].second.second << endl;
  }*/
  for (int i = 0; i < v.size() && tot --> 0; ++i) {
    ans.push_back("S " + toStr(v[i].second.first) + " " + toStr(v[i].second.second));
  }

  for (int i = ans.size() - 1; i >=0; --i) cout << ans[i] << endl;


  tot = s;
  for (int i = vv.size() - 1; i >= 0 and tot --> 0; --i) {
    cout << "B " << vv[i].second.first << " " << vv[i].second.second << endl;
  }

  return 0;
}