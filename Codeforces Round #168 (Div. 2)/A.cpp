// http://codeforces.com/contest/275/problem/A

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

#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define PB push_back
#define MAXNODES 1000

typedef long long int i6;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

const double pi=acos(-1);

int main(){
  int n,t,sum=0;
  int mat[4][4];
  int mat2[4][4];

  
	FR(i,5){
    FR(j,5)
		  mat[i][j]=1;
	}
  
  fr(i,1,4){
   fr(j,1,4){
      int t;
      cin >> t;
		  mat2[i][j]=t;
    }
	}
	
  fr(i,1,4){
    fr(j,1,4)
		  if(mat2[i][j]%2 != 0){
        mat[i][j]     = mat[i][j]==0? 1 : 0;
        mat[i][j-1]   = mat[i][j-1]==0? 1 : 0;
        mat[i-1][j]   = mat[i-1][j]==0? 1 : 0;
        mat[i+1][j]   = mat[i+1][j]==0? 1 : 0;
        mat[i][j+1]   = mat[i][j+1]==0? 1 : 0;
      }
	}
  
  fr(i,1,4){
    fr(j,1,4){
		  cout << mat[i][j];
    }
    cout << endl;
	}

  return 0;
}



