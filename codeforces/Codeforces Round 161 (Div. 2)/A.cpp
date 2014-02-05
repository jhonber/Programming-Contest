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
#define MAXNODES 1000

int mat[5][5];
int posx=0, posy=0;

int find(){
	FR(i,5){
		FR(j,5){
			if(mat[i][j] == 1) {
				posx = i; posy=j;
				return 0;
			}
		}
	}
}

int solv(){
	find();
	int r=0;
	if(posx==2 && posy==2) return 0;
	else{
			r = abs(2-posx) + abs(2-posy);
	}
	return r;
}

int main(){
	FR(i,5){
		FR(j,5){
			cin >> mat[i][j];
		}
	}
	cout << solv() << endl;
	return 0;
}




