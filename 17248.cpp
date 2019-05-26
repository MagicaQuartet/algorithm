#include<cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		int A, B, Z, accZ;
		int s = 0;
		scanf("%d %d %d", &A, &B, &Z);
		accZ = Z;
		
		while (A < B) {
			s++;
			A += accZ;
			accZ += Z;
		}
		
		printf("%d\n", s);
	}
	return 0;
}