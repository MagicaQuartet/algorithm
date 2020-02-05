#include<cstdio>
#include<algorithm>
using namespace std;
int data[3];
int main() {
  while (1) {
    scanf("%d %d %d", data, data+1, data+2);
    if (data[0] == 0 & data[1] == 0 && data[2] == 0) break;
    sort(data, data+3);
    printf("%s\n", data[0]*data[0]+data[1]*data[1]==data[2]*data[2] ? "right" : "wrong");
  }
}