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

struct client {
  int id,a,b;
};

int a,b;

bool comp(client i, client j){
  return (i.a*a + i.b*b < j.a*a + j.b*b);
}

int main(){
  int n,d,x,y;
  cin >> n >> d >> a >> b;

  vector< client > v;
  FR(i,n){
    cin >> x >> y;
    client t; t.id = i+1; t.a = x; t.b = y;
    v.push_back( t );
  }

  sort(all(v),comp);

  vi ans;
  FR(i,n){
    if( v[i].a*a + v[i].b*b <= d){
      ans.push_back(v[i].id);
      d -= v[i].a * a + v[i].b*b;
    }
    else break;
  }

  cout << ans.size() << endl;
  FR(i,ans.size()) cout << ans[i] << " ";

  return 0;
}
