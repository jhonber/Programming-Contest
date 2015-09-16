// https://uva.onlinejudge.org/external/129/12953.pdf

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

struct obj {
  bool col;
  int ind;
  int cnt;
  map<string, int> mapa;
};

bool comp (obj i, obj j) {
  return i.cnt < j.cnt;
}

int main () { __
  int n, m;
  while (cin >> n >> m) {

    vector<int> rows(n), cols(m);
    vector<string> mat[n];
    for (int i = 0; i < n + 1; ++i) {
      if (i < n) {
        for (int j = 0; j < m + 1; ++j) {
          if (j < m) {
            string var;
            cin >> var;
            mat[i].push_back(var);
          }
          else cin >> rows[i];
        }
      }
      else {
        for (int j = 0; j < m; ++j) cin >> cols[j];
      }
    }

    int inf = 10000000;
    vector<obj> v;
    for (int i = 0; i < n; ++i) {
      map<string, int> mapa;
      for (int j = 0; j < m; ++j) mapa[mat[i][j]] = inf;
      obj t;
      t.col = false;
      t.ind = i;
      t.cnt  = mapa.size();
      t.mapa = mapa;
      v.push_back(t);
    }

    for (int i = 0; i < m; ++i) {
      map<string, int> mapa;
      for (int j = 0; j < n; ++j) mapa[mat[j][i]] = inf;
      obj t;
      t.col = true;
      t.ind = i;
      t.cnt  = mapa.size();
      t.mapa = mapa;
      v.push_back(t);
    }

    map<string, int> ans;
    int x = 0;
    while (true) {
      int f = false;
      for (int x = 0; x < v.size(); ++x) {
        obj cur = v[x];
        if (cur.cnt == 1) {
          int ind = cur.ind;
          int cnt = 0;
          int sum = 0;
          int tmp = 0;
          string var;
          if (cur.col) {
            for (int j = 0; j < n; ++j) {
              if (cur.mapa[mat[j][ind]] == inf) {
                cnt ++;
                var = mat[j][ind];
              }
              else tmp += cur.mapa[mat[j][ind]];
            }
            sum = cols[ind];
          }
          else {
            for (int j = 0; j < m; ++j) {
              if (cur.mapa[mat[ind][j]] == inf) {
                cnt ++;
                var = mat[ind][j];
              }
              else tmp += cur.mapa[mat[ind][j]];
            }
            sum = rows[ind];
          }

          int res = (sum - tmp) / max(cnt, 1);
          ans[var] = res;

          for (int i = 0; i < v.size(); ++i) {
            if (v[i].mapa[var]) {
              v[i].mapa[var] = res;
              v[i].cnt --;
            }
          }
          f = true;
        }
      }
      if (!f) break;
    }

    foreach(x, ans) {
      cout << x->first << " " << x->second << endl;
    }
  }
  return 0;
}
