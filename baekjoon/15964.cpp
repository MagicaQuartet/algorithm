#include<cstdio>
#define ll long long
ll A, B;
int main() {
    scanf("%lld %lld", &A, &B);
    printf("%lld\n", (A + B) * (A - B));
}