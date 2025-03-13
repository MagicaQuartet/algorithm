#include<cstdio>
using namespace std;
int R, G, B;
int main() {
    scanf("%d %d %d", &R, &G, &B);
    int ans = 0;
    ans += R / 3 + G / 3 + B / 3;
    R -= R / 3 * 3;
    G -= G / 3 * 3;
    B -= B / 3 * 3;
    while (R * G * B > 0) {
        ans += 1;
        R -= 1;
        G -= 1;
        B -= 1;
    }
    if (R + G + B > 0) {
        if (R + G == 0 || G + B == 0 || B + R == 0) {
            ans += (R + G + B + 2) / 3;
        }
        else {
            int a, b;
            if (R == 0) {
                a = G < B ? G : B;
                b = G < B ? B : G;
            }
            else if (G == 0) {
                a = B < R ? B : R;
                b = B < R ? R : B;
            }
            else {
                a = R < G ? R : G;
                b = R < G ? G : R;
            }
            ans += a + (b - a + 2) / 3;
        }
    }
    printf("%d\n", ans);
}