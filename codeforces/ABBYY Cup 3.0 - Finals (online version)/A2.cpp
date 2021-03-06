// http://codeforces.com/contest/331/problem/A2

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

bool comp(pair<int,int> i, pair<int,int> j) {
  if (i.first == j.first)
    return i.second < j.second;
  return i.first < j.first;
}

int main(){ __
  int n;
  cin >> n;

  vector< pair<int,int> > vv;
  int v[n];
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    vv.push_back(make_pair(v[i],i));
  }

  long long image[321000];
  image[0] = 0LL;
  for (int i = 1; i <= n; ++i) {
    if (v[i-1] > 0)
      image[i] = image[i - 1] + v[i - 1];
    else image[i] = image[i - 1];
  }

  sort(all(vv),comp);

  long long mmax = -LLONG_MAX;
  int a = 0, b = n-1;
  pair<int,int> cur = vv[0];

  for (int i = 1; i < n; ) {
    while (cur.first == vv[i].first && i < n) i++;
    if (i > n) break;
    int dist = 0;
    if (vv[i - 1].first == cur.first)
      dist = vv[i - 1].second - cur.second;

    if (dist) {
      long long psum = image[vv[i - 1].second + 1] - image[cur.second];
      if (cur.first < 0) psum += (2 * cur.first);
      if (mmax < psum ) {
        mmax = psum;
        a = cur.second;
        b = vv[i - 1].second;
      }
    }

    cur = vv[i];
  }

  vector<int> ans(n,1);
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    if (i < a || i > b || ( i > a && i < b && v[i] < 0 )) {
      ans[i] = 0;
      cnt ++;
    }
    else ans[i] = 1;
  }

  cout << mmax << " " << cnt << endl;
  for (int i = 0; i < n; ++i)
    if (!ans[i]) cout << i+1 << " ";

  return 0;
}