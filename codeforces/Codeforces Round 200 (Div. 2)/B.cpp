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

int main(){ //_
	int a,b,c;
//	while(true){
	cin >> a >> b >> c;
//	if(a+b+c ==0)break;
	int ab = (a-c+b) / 2;
	int bc = (c+b-a) / 2;
	int ca = (c-b+a) / 2;
		
	if( (a+b+c)%2 == 0 && (ab+bc+ca == (a+b+c)/2) && (ab>=0 && bc>=0 && ca>=0) && (ab+ca>0 && ca+bc>0 && ab+bc>0)) cout << ab << " " << bc << " " << ca << endl;
	else cout << "Impossible" << endl;
//}
	return 0; 
}
