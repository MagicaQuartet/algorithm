// Baekjoon Online Judge #5354

#include <cstdio>

using namespace std;

int main() {
	int T, J;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &J);

		for (int i = 0; i < J; i++) {
			for (int j = 0; j < J; j++) {
				if (i == 0 || j == 0 || i == J-1 || j == J-1)
					printf("#");
				else
					printf("J");
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}