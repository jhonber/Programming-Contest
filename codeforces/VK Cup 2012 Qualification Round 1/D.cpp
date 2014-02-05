#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define pb push_back

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

set<int> get_divs(int n){
  set<int> d;
  int i=2;
  while(i*i<=n){
    if(n%i == 0){
      d.insert(i);
      d.insert(n/i);
    }
    i++;
  }
  return d;
}

int main(){
  int n;
  cin >> n;

  vi v(n);
  int ans = 0;
  FR(i,n){
    cin >> v[i];
    ans += v[i];
  }

  set<int> divs = get_divs(n);

  foreach(d,divs){
    vi ready(n);
    FR(i,n){
      if(ready[i]) break;
      int t = 0,f = 0;
      for(int j=i; j<n ; j+=*d){
        t += v[j];
        ready[j] = true;
        f++;
      }
      if(f>2) ans = max(ans,t);
    }
  }

  cout << ans;
  return 0;
}
