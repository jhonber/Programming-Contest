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

int main(){ 
	int n, tmp;
	cin >>n;
	vi v(n);
	int bad = 0;
	FR(i,n){
		cin >> v[i];
		if(v[i]<0) bad++;
	}
	int t = ceil(bad/2.0);
	if(!t) t++;
	cout << t << endl;
	int c = 0, c2=0, j = 0;
	vi v2;
	FR(i,n-1){
		if(v[i] < 0) c++;
		if(c==2 && v[i+1]<0){
			v2.PB(i-j+1);
			j = i+1;
			c = 0;
		}
		
		c2++;
	}

	int c3=0;
	FR(i,v2.size()){
		cout << v2[i] << " ";
		c3 += v2[i];
	}
	if(c3<n) cout <<(n-c3);
	return 0; 
}