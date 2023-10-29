#include<cstdio>
using namespace std;
int N;
int main() {
    scanf("%d", &N);
    int a = N / 100;
    int b = (N % 100) / 10;
    int c = N % 10;
    for (int i = a; i <= 9; i++) {
        for (int j = b; j <= 9; j++) {
            if (i * j >= 10) {
                c = 0;
                break;
            }
            for (int k = c; k <= 9; k++) {
                if (i * j == k) {
                    printf("%d%d%d\n", i, j, k);
                    return 0;
                }
            }
            c = 0;
        }
        b = 0;
    }
}