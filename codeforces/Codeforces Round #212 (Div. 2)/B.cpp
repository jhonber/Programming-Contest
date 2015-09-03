// http://codeforces.com/contest/362/problem/B

using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
  int n,m;
  cin >> n >> m;
  if(m==0) {
    cout << "YES";
    return 0;
  }
  vi dirty(m);
  FR(i,m){
    cin >> dirty[i];
  }
  sort(all(dirty));

  if(dirty[0]==1 || dirty[m-1]==n) cout << "NO";
  else {
    FR(i,m-2){
      if(dirty[i]+1 == dirty[i+1] && dirty[i+1] + 1 == dirty[i+2]){
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
  }
  
  return 0;
}
