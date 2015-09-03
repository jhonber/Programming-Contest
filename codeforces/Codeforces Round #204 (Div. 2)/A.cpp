// http://codeforces.com/contest/352/problem/A

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
  int n;
  cin >> n;

  vi v(n);
  int zeros = 0;
  int fives = 0;
  FR(i,n){
    cin >> v[i];
    if(v[i]==0) zeros ++;
    if(v[i]==5) fives ++;
  }

  if(!zeros) cout << -1;
  else {
    if(fives>8){
      int times = fives/9;
      FR(i,times) FR(x,9) cout << 5;
      FR(i,zeros) cout << 0;
    }
    else cout << 0;
  }

  return 0;
}
