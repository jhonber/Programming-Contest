// http://codeforces.com/contest/337/problem/A

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

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
#define M 1000

int main(){ __
    int n,m;
		cin >> n >> m;

		vi v(m);
		FR(i,m){
			cin >> v[i];
		}
		
		sort(all(v));
		
		int ans = 1000000;
		FR(i,m-n+1){
			int t = abs(v[i+n-1] - v[i]);
//			D(v[i+n-1]); D(v[i]);
			ans = t < ans ? t : ans;
		}

		cout << ans;
	
    return 0; 
}
