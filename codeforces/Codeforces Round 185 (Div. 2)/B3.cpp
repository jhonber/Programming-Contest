#include<cstdio>

int main(){
	double a, b, c, d;
	scanf("%lf %lf %lf %lf",&a,&b,&c, &d);
	double p1 = a/b;
	double p2 = c/d;
	printf("%.10lf\n", p1/(1.0 - (1.0-p1)*(1.0-p2)));
	return 0;
}