#include<cstdio>
using namespace std;
int W, H, N, M;
int main() {
    scanf("%d%d%d%d", &W, &H, &N, &M);
    printf("%d\n", ((W + N) / (N + 1)) * ((H + M) / (M + 1)));
}