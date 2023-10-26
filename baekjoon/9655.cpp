#include<cstdio>
using namespace std;
int N;
int main() {
    scanf("%d", &N);
    printf("%s\n", N % 2 ? "SK" : "CY");
}