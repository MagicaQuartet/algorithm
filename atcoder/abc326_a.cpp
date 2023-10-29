#include<cstdio>
using namespace std;
int X, Y;
int main() {
    scanf("%d%d", &X, &Y);
    printf("%s\n", (X < Y && Y - X <= 2) || (Y < X && X - Y <= 3) ? "Yes" : "No");
}