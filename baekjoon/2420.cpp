#include<cstdio>
#define ll long long
ll N, M;
int main() {
    scanf("%lld %lld", &N, &M);
    printf("%lld\n", N - M >= 0 ? N - M : M - N);
}