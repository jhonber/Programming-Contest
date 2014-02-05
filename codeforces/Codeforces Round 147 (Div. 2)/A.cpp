#include<iostream>

#define fr(i,j,n) for(int i=j;i<n;i++)
#define FR(i,n) fr(i,0,n)

using namespace std;

int main(){
    int n, h ,m , h2, m2,c=1,may=0;
    cin >> n;
    
    cin >> h >> m; 
    FR(i,n-1){
        cin >> h2 >> m2;
        if( h2 == h && m2 == m) c++;
        else{
            if(c > may) may = c;
            c=1;
        }
         h = h2; m = m2;
    }
   if(c > may) may = c;
   cout<< may <<endl;
    
    return 0;    
}