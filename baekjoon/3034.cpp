#include<cstdio>
int N,W,H,m;
int main() {
  scanf("%d%d%d",&N,&W,&H);
  while(N--){
    scanf("%d",&m);
    printf("%s\n",W*W+H*H>=m*m?"DA":"NE");
  }
}