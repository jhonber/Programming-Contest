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
  string line;
  cin >> n >> line;

  vi v1, v2;
  FR(i,n*2){
    if(i<n) v1.PB(toInt(line[i]));
    else v2.PB(toInt(line[i]));
  }

  sort(all(v1));
  sort(all(v2));

  int f1 = false, f2 = false, paila = false;
  FR(i,n){
//    D(v1[i]); D(v2[i]);
    if(v1[i]>v2[i]) f1 = true;
    if(v1[i]<v2[i]) f2 = true;
    if(v1[i]==v2[i]) paila = true;
  }
  if(paila) cout << "NO" << endl;
  else {
    if(f1 && !f2 || !f1 && f2) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
