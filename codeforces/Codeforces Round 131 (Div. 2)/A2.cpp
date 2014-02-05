#include<cstdio>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    int i,j,cont=0;
    for(i=0;i<=1001;i++){
        for(j=0;j<=1001;j++){
            if( (i*i)+(j) == n  && (i)+(j*j) == m) {
                cont++;
            }
        }
    }
    printf("%d\n",cont);
}