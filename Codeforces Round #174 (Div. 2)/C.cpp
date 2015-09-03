// http://codeforces.com/contest/284/problem/C

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

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MAXNODES 1000

typedef long long int i6;
typedef vector<i6> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;

class Fenwick{
	vector <long long> v;
	int maxSize;
	
	public:
		Fenwick(int _maxSize) : maxSize(_maxSize+1){
			v = vector <long long>(maxSize, 0LL);
		}
	
		void add(int where, long long what){
			for (where++; where <= maxSize; where += where & -where){
				v[where] += what;
			}
		}
	
		long long query(int where){
			long long sum = v[0];
			for (where++; where > 0; where -= where & -where){
				sum += v[where];
			}
			return sum;
		}
		
		void inc( int a, int b, long long what ) {
			add( a, what );
			add( b+1, -what );
		}

		long long get( int index ) {
			return query(index);
		}
};

const int MAXN = 2 * 1e5 + 5;

int main(){
  int n,op;
  cin >> n;

  Fenwick tree = Fenwick(MAXN);
  long long sum = 0;
  int size = 1;

  FR(i,n){
    cin >> op;
    if(op==1){
      int a; long long x;
      cin >> a >> x;
      tree.inc(0, a-1, x);
      sum += (a*x);
    }
    else if(op==2){
      long long t;
      cin >> t;
      tree.inc(size,size,t);
      sum += t;
      size++;
   }
    else if(op==3){
      size--;
      long long dec = tree.get(size);
      tree.inc(size,size,-dec);
      sum -= dec;
    }
    double res = 1.0 * sum / size;
    printf("%.7lf\n",res);
  }
 
  return 0;
}



