#include<cstdio>
using namespace std;
int a, b, c;
int main() {
    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 || b == 0 || c == 0) break;
        if (a >= b + c || b >= a + c || c >= a + b) printf("Invalid\n");
        else if (a == b && b == c) printf("Equilateral\n");
        else if (a == b || b == c || c == a) printf("Isosceles\n");
        else printf("Scalene\n");
    }
}