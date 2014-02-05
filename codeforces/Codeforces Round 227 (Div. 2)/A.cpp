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

string pre(int t){
  if(t<10) return "0"+toStr(t);
  if(t==24) return "00";
  return toStr(t);
}

int main(){
  int s1,s2, t1,t2;

  scanf("%d:%d", &s1,&s2);
  scanf("%d:%d", &t1,&t2);

  if(s1 == 0) s1 = 24;
  if(t1 == 0) t1 = 24;

  int h1 = (s1*60)+s2, h2=(t1*60)+t2;

  if(h1>h2){
    int ans = h1-h2;
    cout << pre(ans/60) << ":" << pre(ans%60) << endl;
  }
  else {
    int ans = ((24*60) - h2) + h1;
    cout << pre(ans/60) << ":" << pre(ans%60) << endl;
  }

  return 0;
 }
