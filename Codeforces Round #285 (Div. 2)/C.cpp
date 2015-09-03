// http://codeforces.com/contest/501/problem/C

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

  priority_queue< pair<int,int> > Q;
  map< int, pair<int,int> > mapa;
  int d,s;
  for (int i = 0; i < n; ++i) {
    cin >> d >> s;
    if (d == 1) Q.push(make_pair(i,s));
    else mapa[i] = make_pair(d,s);
  }

  set< pair<int,int> > ans;
  while (!Q.empty()) {
    pair<int,int> cur = Q.top(); Q.pop();
    mapa[cur.second].first --;
    mapa[cur.second].second ^= cur.first;
    int t1 = cur.first;
    int t2 = cur.second;
    if (t1 > t2) swap(t1,t2);
    ans.insert(make_pair(t1,t2));

    if (mapa[cur.second].first == 1) {
      Q.push(make_pair(cur.second,mapa[cur.second].second));
      mapa.erase(cur.second);
    }
  }

  cout << ans.size() << endl;
  foreach(i,ans) cout << i->first << " " << i->second << endl;

  return 0;
}