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
	cin >> n;
	vi v(n);

	int ans = 0;
	map<int,int> mapa1, mapa2;
	FR(i,n){
		cin >> v[i];
		mapa1[i] = v[i];
		mapa2[v[i]] = i;
	}

	int f = false, f2 = false;
	FR(i,n){
		if(i == mapa2[i]) ans ++;
		else {
			f2 = true;
			if(mapa1[i] == mapa2[i]) f = true;
		}
	}
	if(!f2){
		cout << n << endl;
		return 0;
	}
	if(f2 && f) ans += 2;
	else if(ans && !f) ans++;
	else if(!f && f2 && !ans) ans++;
	
	cout << ans << endl;
	return 0; 
}
