// http://codeforces.com/contest/490/problem/B

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

int main(){ //__
  int n;
  cin >> n;

  int mmax = 1e7;
  int a,b,last;
  int ans[n + 1];
  map< int, pair<int,int> > front, back;
  set<int> st;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (n % 2 != 0 && !b) b = mmax;
    st.insert(a); st.insert(b);
    front[a] = make_pair(a,b);
    back[b]  = make_pair(a,b);
  }

  foreach(x,st) {
    if (front.find(*x) == front.end()) {
      last = *x;
      break;
    }
  }

  if (n % 2 != 0) {
    front[last] = make_pair(last,0);
    back[0]  = make_pair(last,0);
  }

  map<int, pair<int,int> > :: iterator it;

  priority_queue< pair<int,int> > Q;
  Q.push(make_pair(front[0].second, 1));
  if (n % 2 != 0) Q.push(make_pair(back[0].first, n + 1 - 2));
  else Q.push(make_pair(back[0].first, n - 2));
  ans[1] = front[0].second;
  if (n % 2 != 0)  ans[n + 1 - 2] = back[0].first;
  else ans[n - 2] = back[0].first;

  it = front.find(0);
  front.erase(it);

  it = back.find(0);
  back.erase(it);

  while (!Q.empty()) {
    pair<int,int> cur = Q.top(); Q.pop();
    it = front.find(cur.first);
    if ( it != front.end() && cur.second + 2 < n ) {
      ans[cur.second + 2] = front[cur.first].second;
      Q.push(make_pair(front[cur.first].second,cur.second + 2));
      front.erase(it);
    }

    it = back.find(cur.first);
    if ( it != back.end() && cur.second - 2 >= 0 ) {
      ans[cur.second - 2] = back[cur.first].first;
      Q.push(make_pair(back[cur.first].first,cur.second - 2));
      back.erase(it);
    }
  }

  for (int i = 0; i < n; ++i)
    cout << ans[i] << " ";

  return 0;
}