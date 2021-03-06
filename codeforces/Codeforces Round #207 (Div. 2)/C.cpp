// http://codeforces.com/contest/357/problem/C

using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define all(x) x.begin(),x.end()
#define D(x) cout<< #x " = "<<(x)<<endl
#define PB push_back
#define MK make_pair
#define F first
#define S second

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef vector<pii> vpii;

int main(){
  int n,m,l,r,x;
  cin >> n >> m;
  vi ans(n+1,0);
  set<int> st;

  FR(i,n) st.insert(i+1);
  
  FR(i,m){
    cin >> l >> r >> x;
    set<int> :: iterator it = st.lower_bound(l);
    vi toErase;
    while( it != st.end() ){
      int cur = *it;
      if(cur > r) break;
      if(cur != x){
        toErase.PB(cur);
        ans[cur] = x;
      }
      ++it;
    }

    FR(j,toErase.size()) st.erase(toErase[j]);
  }

  fr(i,1,n+1) cout << ans[i] << " ";

  return 0;
}
