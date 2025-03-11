#include<cstdio>
using namespace std;
int N, M;
char C;
int main() {
    scanf("%d", &N);
    while (N--) {
        scanf("%d %c", &M, &C);
        for (int i = 0; i < M; i++) {
            char c = 'A' + (C - 'A' + i) % 26;
            for (int j = 0; j < i + 1; j++) {
                printf("%c", c);
            }
            printf("\n");
        }
        printf("\n");
    }
}
