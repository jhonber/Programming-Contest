// http://codeforces.com/contest/278/problem/A

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

int main(){
  int n,a,b;
  cin >> n;

  vi v(n);
  FR(i,n){
    cin >> v[i];
  }

  cin >> a >>b;
  a--; b--;

  if(a==b){
    cout << 0 << endl;
    return 0;
  }

  int ans1 = 0, ans2 = 0;
  fr(i,min(a,b),max(a,b)){
    ans1 += v[i];
  }

  for(int i = max(a,b); i%n!=min(a,b) ;i++){
    ans2 += v[i%n];
  }

  cout << min(ans1,ans2);

  return 0;
}
