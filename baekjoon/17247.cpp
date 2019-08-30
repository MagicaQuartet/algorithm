#include<cstdio>

using namespace std;

int main() {
	int N, M, num;
	int x1 = -1, y1, x2, y2;
	scanf("%d %d", &N, &M);
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &num);
			if (num == 1) {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					printf("%d\n", (x1 - i < 0 ? i - x1 : x1 - i) + (y1 - j < 0 ? j - y1 : y1 - j));
					return 0;
				}
			}
		}
	}
}

/* 별 생각 안해도 된다 */