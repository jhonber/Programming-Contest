// http://codeforces.com/contest/472/problem/C

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
  cin >> n;

  vector< pair<string,string> > v;
  vector< pair<string,string> > vv(n);
  string a,b;

  for (int i=0; i<n; ++i) {
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }

  vector<int> mark(n,0);
  int t;
  for (int i=0; i<n; ++i) {
    cin >> t;
    t--;
    vv[i] = v[t];
  }

  bool f = true;
  string less = min(vv[0].first, vv[0].second);
  for (int i=1; i<n; ++i) {
    if (less > vv[i].first && less > vv[i].second) {
      f = false;
      break;
    }
    else {
      string tmp = min(vv[i].first,vv[i].second);
      if (tmp > less) {
        less = tmp;
      }
      else {
        less = max(vv[i].first,vv[i].second);
      }
    }
  }
  if (f) {
    cout << "YES";
    return 0;
  }
  less = max(vv[0].first, vv[0].second);
  for (int i=1; i<n; ++i) {
    if (less > vv[i].first && less > vv[i].second) {
      f = false;
      break;
    }
    else {
      string tmp = min(vv[i].first,vv[i].second);
      if (tmp > less) {
        less = tmp;
      }
      else {
        less = max(vv[i].first,vv[i].second);
      }
    }
  }

  cout << (f ? "YES" : "NO");
  return 0;
}