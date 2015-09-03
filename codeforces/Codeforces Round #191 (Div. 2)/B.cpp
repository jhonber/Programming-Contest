// http://codeforces.com/contest/327/problem/B

using namespace std;
#include<bits/stdc++.h>

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
#define MAX 2000000

bool cb[MAX+1];

void criba(){
        memset(cb,true,sizeof(cb));
        cb[0] = cb[1] = false;
        int lim = sqrt((double)MAX)+1;
        FR(i,lim){
                if( cb[i] )
                        for( int j=i*i; j<MAX; j+=i ) cb[j] = false;
        }
}

int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
		criba();
    int n;
		cin >> n;
		int c = 0, i=0;
		while(c<n){
			if(cb[i]) {
				cout << i << " ";	
				c++;
			}
			i++;
		}
		cout << endl;
    return 0; 
}


