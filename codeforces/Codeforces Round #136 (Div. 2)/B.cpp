// http://codeforces.com/contest/221/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

bool good(int a, int b){
  string aa = toStr(a);
  string bb = toStr(b);

  for(int i=0; i<aa.size(); ++i){
    for(int j=0; j<bb.size(); ++j){
      if(aa[i]==bb[j])
        return true;
    }
  }

  return false;
}

int main(){__
  int x;
  cin >> x;

  if(x==1){
    cout << 1;
    return 0;
  }

  set<int> st;
  for(int i=1; i*i<=x; ++i){
    if(x%i == 0){
      if(good(x,x/i))
        st.insert(x/i);

      if(good(x,i))
        st.insert(i);
    }
  }

  cout << st.size();
  return 0;
}