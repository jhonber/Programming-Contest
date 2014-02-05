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

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
#define MAX 2000000

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){
	int n,m;
	char c;
	cin >> n >> m >> c;

	char mat[n+5][m+5];
	memset(mat,'.',sizeof(mat));
	fr(i,1,n+1){
		fr(j,1,m+1){
			cin >> mat[i][j];
		}
	}

	set< pair<int,int> > st;
	map<char,int> ya;
	fr(i,1,n+1){
		fr(j,1,m+1){
			if(mat[i][j]==c || mat[i][j]=='.') continue;
			for(int x=1; x<8; x+=2){
				char t = mat[i+dx[x]][j+dy[x]];
				if(t == c && !ya[mat[i][j]]){
					st.insert(MK(i,j));
					ya[mat[i][j]] = 1;
				}
			}
		}
	}

	cout << st.size();

	return 0;
}