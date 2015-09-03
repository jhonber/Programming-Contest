// http://codeforces.com/contest/493/problem/C

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

int main(){ __
  int n;
  cin >> n;

  map<int,int> cnt1,cnt2;
  set<int> st,st1,st2;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    cnt1[v[i]] ++;
    st.insert(v[i]);
    st1.insert(v[i]);
  }

  int m;
  cin >> m;

  vector<int> vv(m);
  for (int i = 0; i < m; ++i) {
    cin >> vv[i];
    cnt2[vv[i]] ++;
    st.insert(vv[i]);
    st2.insert(vv[i]);
  }

  vector<long long> img1(cnt1.size() + 1), img2(cnt1.size() + 1), img3(cnt2.size() + 1), img4(cnt2.size() + 1);
  img1[0] = 0;
  int i = 1;
  foreach(x,cnt1) {
    img1[i] = img1[i - 1] + (x->second * 2LL);
    i ++;
  }

  img2[0] = 0;
  i = 1;
  foreach(x,cnt1) {
    img2[i] = img2[i - 1] + (x->second * 3LL);
    i ++;
  }

  img3[0] = 0;
  i = 1;
  foreach(x,cnt2) {
    img3[i] = img3[i - 1] + (x->second * 2LL);
    i ++;
  }

  img4[0] = 0;
  i = 1;
  foreach(x,cnt2) {
    img4[i] = img4[i - 1] + (x->second * 3LL);
    i ++;
  }

  vector<int> cool1(st1.size());
  vector<int> cool2(st2.size());

  int k = 0;
  foreach(x,st1)
    cool1[k++] = *x;
  k = 0;
  foreach(x,st2)
    cool2[k++] = *x;

  long long mmin = -LLONG_MAX;
  long long a,b,aa,bb;
  vector<int>::iterator it1, it2;

  foreach(x,st) {
    it1 = lower_bound(all(cool1),*x);
    it2 = lower_bound(all(cool2),*x);

    int p1 = it1 - cool1.begin();
    a = img1[p1] + (img2[cnt1.size()] - img2[p1]);

    int p2 = it2 - cool2.begin();
    b = img3[p2] + (img4[cnt2.size()] - img4[p2]);

    long long tmp = a - b;
    if (mmin < tmp) {
      mmin = tmp;
      aa = a;
      bb = b;
    }
    if (mmin == tmp && a > aa) {
      aa = a;
      bb = b;
    }
  }

  a = img1[st1.size()];
  b = img3[st2.size()];
  long long tmp = a - b;
  if (mmin < tmp) {
    mmin = tmp;
    aa = a;
    bb = b;
  }

  if (mmin == tmp && a > aa) {
    aa = a;
    bb = b;
  }

  a = img2[st1.size()];
  b = img4[st2.size()];
  tmp = a - b;
  if (mmin < tmp) {
    mmin = tmp;
    aa = a;
    bb = b;
  }

  if (mmin == tmp && a > aa) {
    aa = a;
    bb = b;
  }

  cout << aa << ":" << bb;
  return 0;
}