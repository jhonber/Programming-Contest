// http://codeforces.com/contest/315/problem/A

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
#define Dbg if(1)
#define PB push_back
#define M 1000

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<int,int> vii;
typedef vector<vi> vvi;


int main(){
    int n;
		cin>>n;
    
    vector<int> p(n),s(n);
    FR(i,n){
        cin>>p[i]>>s[i];
    }
    int ans = 0;
    FR(i,n){
        int t = 0;
        FR(j,n){
            if(p[i]==s[j] and i!=j) t = 1;
        }
        if(!t) ans++;
    }
    cout << ans << endl;
    
    
    return 0; 
}



