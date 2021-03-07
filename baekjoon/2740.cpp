#include<cstdio>
int N, M, K;
int A[101][101], B[101][101];
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d %d", &M, &K);
    for (int i=0; i<M; i++) {
        for (int j=0; j<K; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<K; j++) {
            int num = 0;
            for (int k=0; k<M; k++) {
                num += A[i][k] * B[k][j];
            }
            printf("%d ", num);
        }
        printf("\n");
    }
}