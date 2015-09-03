// http://codeforces.com/contest/567/problem/D

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

pair<int,int> getMax(map<int,int> &mapa) {
  map<int,int> :: iterator it = mapa.end();
  --it;
  return make_pair(it->first, it->second);
}

int main() {
  int n,k,a,m;
  cin >> n >> k >> a >> m;

  a++;

  set< pair<int, int> > st;
  st.insert(make_pair(1, n));

  map< pair<int,int>, int > mapa;
  set< pair<int, int> > :: iterator low;
  pair<int, int> left, right;

  int tot = n / a;
  if (n % a >= a - 1) tot ++;
  mapa[make_pair(1, n)] = tot;

  int i = 0;
  for ( ; i < m; ++i) {
    int q;
    cin >> q;

    low = st.lower_bound(make_pair(q, q));
    if (low == st.end() or (*low).first > q) low --;

    left.first  = (*low).first;
    left.second = q - 1;

    right.first  = q + 1;
    right.second = (*low).second;

    pair<int,int> tmp = make_pair((*low).first, (*low).second);
    tot -= mapa[tmp];
    st.erase(*low);

    int s1 = (left.second - left.first) + 1;
    int s2 = (right.second - right.first) + 1;

    if (s1) st.insert(left);
    if (s2) st.insert(right);

    int aa = s1 / a;
    int bb = s2 / a;


    if (s1 % a >= a - 1) aa ++;
    if (s2 % a >= a - 1) bb ++;

    tot += aa + bb;
    mapa[left]  = aa;
    mapa[right] = bb;

    if (tot < k) {
      cout << i + 1;
      return 0;
    }
  }

  cout << -1;
  return 0;
}