using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;
typedef map<string,int> msi;

void out(vs names){
  FR(i,names.size()){
      if(names.size()==1) cout << names[i] << ".";
      else {
        if(i!=names.size()-1) cout << names[i] << ", ";
        else cout << names[i] << ".";
      }
    }
}

int main(){
  int n,a,b,c;
  cin >> n;
  msi taxi, pizza, girl;
  vs names;
  FR(i,n){
    int t; string name;
    cin >> t >> name;
    names.PB(name);
    FR(i,t){
      scanf("%d-%d-%d",&a,&b,&c);
      vi v(6);
      v[0] = a/10; v[1] = a%10; v[2] = b/10; v[3] = b%10; v[4] = c/10; v[5] = c%10;
      if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[3] == v[4] && v[4] == v[5]) taxi[name] ++;
      else {
        if(v[0] > v[1] && v[1] > v[2] && v[2] > v[3] && v[3] > v[4] && v[4] > v[5]) pizza[name] ++;
        else girl[name] ++;
      }
    }
  }

  int MAXT = 0;
  int MAXP = 0;
  int MAXG = 0;

  vs vt,vp,vg;

  FR(i,names.size()) if( taxi[names[i]] > MAXT )  MAXT = taxi[names[i]];
  FR(i,names.size()) if( pizza[names[i]] > MAXP ) MAXP = pizza[names[i]];
  FR(i,names.size()) if( girl[names[i]] > MAXG )  MAXG = girl[names[i]];

  FR(i,names.size()) if( taxi[names[i]] == MAXT )  vt.PB(names[i]);
  FR(i,names.size()) if( pizza[names[i]] == MAXP ) vp.PB(names[i]);
  FR(i,names.size()) if( girl[names[i]] == MAXG )  vg.PB(names[i]);

  printf("If you want to call a taxi, you should call: ");
  if(MAXT==0) out(names);
  else out(vt);

  cout << endl;
  printf("If you want to order a pizza, you should call: ");
  if(MAXP==0) out(names);
  else out(vp);

  cout << endl;
  printf("If you want to go to a cafe with a wonderful girl, you should call: ");
  if(MAXG==0) out(names);
  else out(vg);
  cout << endl;

  return 0;
}

