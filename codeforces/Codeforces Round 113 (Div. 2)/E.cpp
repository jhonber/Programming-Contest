#include<cstdio>
#include<cstring>
#define MOD 1000000007
#define M 10000000

int dp[M+10][4];

int main(){
  int n;
  memset(dp,0,sizeof(dp));
  scanf("%d",&n);
  dp[0][0] = 1;
  for(int i = 1; i<= n;++i)
    for(int j = 0 ; j < 4; ++j )
      for(int k = 0; k< 4; ++k)
        if(j != k){
          dp[i][j] += dp[i-1][k];
          dp[i][j] %=MOD;
        }
        
  printf("%d\n",dp[n][0]);
  return 0;
}