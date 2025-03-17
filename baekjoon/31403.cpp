#include<cstdio>
using namespace std;
int A, B, C;
int jssum(int a, int b) {
    int mul = 10;
    while (mul <= 10000) {
        if (b < mul) {
            break;
        }
        mul *= 10;
    }
    return a * mul + b;
}
int main() {
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", A + B - C);
    printf("%d\n", jssum(A, B) - C);
}