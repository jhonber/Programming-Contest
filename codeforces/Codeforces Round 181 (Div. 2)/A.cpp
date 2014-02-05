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

  int main(){
    int n;
    cin >> n;
    set<int> v;
    FR(i,n){
      int t;
      cin >> t;
      v.insert(t);
    }
    
    set<int> a, b;
    set<int> ::iterator ix = v.begin();
    a.insert(*ix);
    v.erase(*ix);
    set<int> ::iterator iy = v.end();
    --iy;
    if((*iy)!=0){
      b.insert(*iy);
      v.erase(*iy);
    }
    else{
      for(set<int> :: iterator it=v.begin();;){
        if((*it)>0){
          b.insert(*it);
          v.erase(*it);
          break;
        }
        else {
          b.insert(*it); v.erase(*it);

          b.insert(*v.begin()); v.erase(*v.begin());
          break;
        }
      }
    }
   
    set<int> ::iterator it,it2,it3;
    cout << a.size() << " ";
    for(it=a.begin();it!=a.end();++it) cout << *it  << " ";
    cout << endl;
    cout << b.size()<< " ";
    for(it2=b.begin();it2!=b.end();++it2) cout << *it2 << " " ;
    cout << endl;
    cout << v.size() << " ";
    for(it3=v.begin();it3!=v.end();++it3) cout << *it3 << " ";
    cout << endl;
    return 0;
  }
