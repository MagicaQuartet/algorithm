#include<cstdio>

using namespace std;

int main() {
	int N;
	int q, r;
	scanf("%d", &N);
	
	q = (N-1)/14;
	r = (N-1)%14;
	
	if (r == 2 || r == 6 || r == 10) {
		if (q < 3) {
			printf("tururu");
			for (int i=0; i<q; i++)
				printf("ru");
		}
		else
			printf("tu+ru*%d", q+2);
	}
	else if (r == 3 || r == 7 || r == 11) {
		if (q < 4) {
			printf("turu");
			for (int i=0; i<q; i++)
				printf("ru");
		}
		else
			printf("tu+ru*%d", q+1);
	}
	else if (r == 0 || r == 12)
		printf("baby");
	else if (r == 1 || r == 13)
		printf("sukhwan");
	else if (r == 4)
		printf("very");
	else if (r == 5)
		printf("cute");
	else if (r == 8)
		printf("in");
	else if (r == 9)
		printf("bed");
	printf("\n");
}