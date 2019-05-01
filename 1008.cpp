#include<cstdio>

using namespace std;

int main() {
	double A, B;	
	
	scanf("%lf %lf", &A, &B);
	printf("%.10lf\n", A/B);
	return 0;
}

/* 허용 오차 자릿수에 유의하자 */