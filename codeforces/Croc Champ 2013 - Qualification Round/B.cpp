// http://codeforces.com/contest/291/problem/B

using namespace std;
#include <bits/stdc++.h>

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define all(x) x.begin(),x.end()
#define D(x) cout<< #x " = "<<(x)<<endl
#define PB push_back
#define MK make_pair

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

typedef long long int ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;


int main(){
	string s;
	while(getline(cin,s)){
		
		int f = false;
		FR(i,s.size()){
			if(s[i]==' ' && !f)continue;
			else {
				f = true;
				if(s[i]=='"'){
					cout << "<";
					int j = i+1;
					for(;j<s.size();j++){
						if(s[j]=='"') break;
						cout << s[j];
					}
					cout << ">" << endl;
					i = j+1;
				}
				else {
					if(s[i]==' ') continue;
					cout << "<";
					int j = i;
					for(;j<s.size();j++){
						if(s[j]==' ') break;
						cout << s[j];
					}
					cout << ">" << endl;
					i = j;
				}
			}
		}
	}
	return 0;
}
