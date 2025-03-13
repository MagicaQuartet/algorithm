#include<cstdio>
using namespace std;
int ax, ay, az, cx, cy, cz;
int main() {
    scanf("%d %d %d %d %d %d", &ax, &ay, &az, &cx, &cy, &cz);
    printf("%d %d %d\n", cx - az, cy / ay, cz - ax);
}