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
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;

const double EPS = 1e-3;

string nums = "0123456789";

char sum(char n){
  if(n=='9') return '0';
  FR(i,nums.size()) if(nums[i]>n) return nums[i];
}

int main(){
  string s;
  cin >> s;
  istringstream sp(s);
  string pint, pfrac;
  getline(sp,pint,'.');
  getline(sp,pfrac,'.');
  
  int t = pint.size();
  if( pint[t-1]!='9' && '5' > pfrac[0]) cout << pint << endl;
  else if(pint[t-1]!='9' && '5' <= pfrac[0]) {
    char n = pint[t-1];
    for(int i=t-1; i>=0; i--){
      char res = sum(pint[i]);
      if(res!=0){
        pint[i] = res;
        cout << pint << endl;
        return 0;
      }
      else pint[i] = '0';
    }    
  }
  else cout << "GOTO Vasilisa." << endl;
  
  return 0;
}