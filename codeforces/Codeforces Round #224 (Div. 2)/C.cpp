// http://codeforces.com/contest/382/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define fr(i,j,n) for(int i=j;i<n;i++)
#define FR(i,n) fr(i,0,n)
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  int n;
  cin >> n;

  vi v(n);
  set<int> st;

  FR(i,n) {
    cin >> v[i];
    st.insert(v[i]);
  }

  if(n==1){
    cout << -1 << endl;
    return 0;
  }


  if(st.size()==1){
    cout << 1 << endl << v[0] << endl;
    return 0;
  }

  sort(all(v));

  set<int> st2;
  FR(i,n-1){
    st2.insert( v[i+1]-v[i] );
    if(st2.size()>2){
      cout << 0 << endl;
      return 0;
    }
  }

  int per = *st2.begin();

  if(!per){
    cout << 0 << endl;
    return 0;
  }

  if(st2.size()==1){
    if(n==2){
      if( (v[1]-v[0])%2 == 0 ){
        cout << 3 << endl;
        cout << v[0]-per << " " <<  v[0] + ((v[1]-v[0])/2)  << " " << v[v.size()-1] + per << endl;
      }
      else cout << 2 << endl << v[0]-per << " " << v[v.size()-1]+per << endl;
    }
    else {
      cout << 2 << endl << v[0]-per << " " << v[v.size()-1]+per << endl;
    }
    return 0;
  }
  else {
    set<int> ans;
    FR(i,v.size()-1){
      if(v[i]+per == v[i+1]) continue;
      else {
        v[i] = v[i]+per;
        ans.insert(v[i]);
        i--;
      }
    }

    if(ans.size()==1){
      cout << 1 << endl << *ans.begin() << endl;
      return 0;
    }
  }

  cout << 0 << endl;

  return 0;
}
