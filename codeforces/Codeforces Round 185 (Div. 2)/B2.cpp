#include<cstdio>

int main(){
	double a, b, c, d;
	scanf("%lf %lf %lf %lf",&a,&b,&c, &d);
	double p1 = a/b;
	double p2 = c/d;
	double ans = p1;
	double k = (1.0-p1)*(1.0-p2);
	double j = k;
	int t = 7000;
	while(t--){
		ans += k*p1;
		k *= j;
	}

	printf("%.10lf\n", ans);
	return 0;
}