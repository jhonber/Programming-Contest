#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m,max=0,cont=1;
    double vecn[10010],vecm[10010];
    vector<int> maxs;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vecn[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>vecm[i];
    }

    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            double res = vecm[i]/vecn[j];
            double t = res - (int)res;

            if( t==0.0 && res >= (double)max){
                max = res;
                maxs.push_back((int) res);
            }
        }
    }
    
    int tmp=maxs[maxs.size()-1];
    if(maxs.size()>1){
        for(int i=maxs.size()-2; i>=0; i--){
            if( tmp == maxs[i] ) cont++;
            else break;
        }
        cout<<cont<<endl;
    }
    else cout<<1<<endl;
}