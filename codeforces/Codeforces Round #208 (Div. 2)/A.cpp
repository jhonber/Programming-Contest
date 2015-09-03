// http://codeforces.com/contest/358/problem/A

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

bool intersection(pii a, pii b){
  if(b.F > a.F && b.F < a.S && b.S > a.S) return true;
  return false;
}

int main(){
  int n;
  cin >> n;
  vpii pairs(n-1);
  vi p(n);

  FR(i,n) cin >> p[i];
  FR(i,n-1) pairs[i] = MK( min(p[i],p[i+1]), max(p[i],p[i+1]) );
  
  sort(all(pairs));
  
  FR(i,n-2){
    fr(j,i+1,n-1){
      if(intersection(pairs[i], pairs[j])){
        cout << "yes";
        return 0;
      }
    }
  } 
 
  cout << "no";
  return 0;
}
