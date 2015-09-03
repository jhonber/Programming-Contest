// http://codeforces.com/contest/501/problem/B

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

int main() { __
  int n;
  cin >> n;

  vector< pair<string,string> > mapa;
  map<string,string> mapa2;
  string a,b;

  for (int i= 0; i < n; ++i) {
    cin >> a >> b;
    mapa.push_back(make_pair(a,b));
    mapa2[a] = b;
  }


  set<string> ready;
  vector< pair<string,string> > ans;

  for (int i = 0; i < n; ++i){
    pair<string,string> cur = mapa[i];
    if (!ready.count(cur.first)) {
      string old = cur.first;
      string act = cur.second;
      ready.insert(old);
      ready.insert(act);
        while (mapa2.find(act) != mapa2.end()) {
          act = mapa2[act];
          ready.insert(act);
        }
      ans.push_back(make_pair(old,act));
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i].first << " " << ans[i].second << endl;


  return 0;
}