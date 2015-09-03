// http://codeforces.com/contest/493/problem/A

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

struct p {
  string team;
  int min = 0;
  int num = 0;
  int y = 0;
  int r = 0;
  int mark = false;
};

bool comp(p i, p j) {
  return i.min < j.min;
}

int main(){ //__
  string t1,t2;
  cin >> t1 >> t2;
  int n;
  cin >> n;


  map<char,string> mapa;
  mapa['h'] = t1;
  mapa['a'] = t2;
  int min;
  char team;
  int num;
  char card;
  vector<p> v;
  vector<p> ans;

  for (int i = 0; i < n; ++i) {
    cin >> min >> team >> num >> card;
    int f = false;
    for (int j = 0; j < v.size(); ++j) {
      if (mapa[team] == v[j].team && num == v[j].num) {
        if (card == 'y') v[j].y ++;
        if (card == 'r') v[j].r ++;
        v[j].min = min;
        f = true;
        break;
      }
    }

    if (!f) {
      p player;
      player.min  = min;
      player.team = mapa[team];
      player.num = num;
      if (card == 'y') player.y = 1;
      if (card == 'r') player.r = 1;
      v.push_back(player);
    }


    for (int j = 0; j < v.size(); ++j) {
      if (v[j].mark) continue;
      if (mapa[team] == v[j].team && num == v[j].num && (v[j].y > 1 || v[j].r > 0)) {
        ans.push_back(v[j]);
        v[j].mark = true;
        break ;
      }
    }
  }

  sort(all(ans),comp);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].team << " " << ans[i].num << " " << ans[i].min << endl;
  return 0;
}