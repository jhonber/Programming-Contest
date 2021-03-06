// http://codeforces.com/contest/172/problem/A

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
typedef vector<int> vi;
typedef vector<string> vs;

int main(){
  int n;
  cin >> n;
  vs v;
  FR(i,n){
    string s;
    cin >> s;
    v.PB(s);
  }
  
  int ans = 0;
  FR(i,v[0].size()){
    FR(j,n-1){
      if(v[j][i] != v[j+1][i]) {
        cout << ans << endl;
        return 0;
      }
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
  
  
  
  
  
  
  
  
  
  
  
  