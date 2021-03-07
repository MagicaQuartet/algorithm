#include<cstdio>
#include<vector>
using namespace std;
#define INF 1000
#define ll long long
#define vi vector<int>
#define vvi vector<vi >
int N;
ll B;
vvi A;
vvi matmul(vvi X, vvi Y) {
    vvi ret(A);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int num = 0;
            for (int k=0; k<N; k++) {
                num += X[i][k] * Y[k][j];
                num %= INF;
            }
            ret[i][j] = num;
        }
    }
    return ret;
}
vvi solve(ll b) {
    if (b == 1) {
        return vvi(A);
    }

    vvi divided = solve(b/2);
    vvi ret = matmul(divided, divided);
    if (b%2) ret = matmul(ret, A);
    return ret;
}
int main() {
    scanf("%d %lld", &N, &B);
    for (int i=0; i<N; i++) {
        A.push_back(vi(N, 0));
        for (int j=0; j<N; j++) {
            int num;
            scanf("%d", &num);
            num %= INF;
            A[i][j] = num;
        }
    }
    vvi ret = solve(B);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
}