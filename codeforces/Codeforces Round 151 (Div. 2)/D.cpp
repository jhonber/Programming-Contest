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
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int N = 100005;
set<int> hash[N];
vi color(N);

int main(){
  int n,m,a,b;
  cin >> n >> m;

  fr(i,1,n+1) cin >> color[i];

  FR(i,m){
    cin >> a >> b;
    if(color[a]==color[b]) continue;
    hash[color[a]].insert(color[b]);
    hash[color[b]].insert(color[a]);
  }

  int ind = 1, maxn = -1;
  fr(i,1,n+1){
    if( (int)hash[color[i]].size() > maxn || (int)hash[color[i]].size() == maxn && color[i] < ind ){
      maxn = (int)hash[color[i]].size();
      ind = color[i];
    }
  }

  cout << ind << endl;

  return 0;
}
