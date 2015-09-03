// http://codeforces.com/contest/378/problem/B

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


struct P {
  int val;
  int sem;
  int pos;
};

bool comp(P i, P j){
  return i.val < j.val;
}

int main(){ __
  int n;
  cin >> n;

  vector< P > v;
  vector<int> ans1(n,0);
  vector<int> ans2(n,0);

  for (int i=0; i<n; ++i){
    int a,b;
    cin >> a >> b;
    P t1, t2;
    t1.val = a; t1.sem = 1; t1.pos = i;
    t2.val = b; t2.sem = 2; t2.pos = i;
    v.push_back(t1);
    v.push_back(t2);
  }

  sort (all(v), comp);

  for (int i=0; i<n/2; ++i)
    ans1[i] = ans2[i] = true;


  for (int i=0; i<n; ++i){
    if (v[i].sem == 1)
      ans1[v[i].pos] = true;
    else
      ans2[v[i].pos] = true;
  }

  for (int i=0; i<n; ++i)
    cout << ans1[i];

  cout << endl;
  for (int i=0; i<n; ++i)
    cout << ans2[i];

  return 0;
}