#include<bits/stdc++.h>
using namespace std;

bool ck(char c){
    if(c=='.' | c=='!' || c=='?') return true;
    return false;
}

int main(){
    int n; string line;
    getline(cin,line);
    n = atoi(line.c_str());
    getline(cin,line);
    
    int c = 0,f = true;
    vector<int> v;
    for(int i=0; i<line.size();i++){
        c++;
        if(ck(line[i])){
            v.push_back(c);
            if(line[i+1]==' ') i++;
            if(c > n){
                f = false;
                break;
            }
            c = 0;
        }
    }
    
    if(f) {
        int acum = 0, ans = 0;
        int paila = false;
        for(int i=0;i<v.size();i++){
            acum += v[i];
            if(i>0 && !paila) acum ++;
            if(acum > n){
                ans ++;
                i -= 1;
                acum = 0;
                paila = true;
                continue;
            }
            if(i==v.size()-1){
                if(v[v.size()-1] > 0) ans++;
            }
            paila = false;
        }
        cout << ans << endl;
    }
    else cout << "Impossible" << endl;

    return 0;
}