#include<cstdio>
int root, _root;
char c;
int main() {
  while(1) {
    root = 0;
    while((c=getchar())!='\n') {
      root += c-48;
    }
    
    if (!root) {
      break;
    }
    
    while (root >= 10) {
      _root = 0;
      while(root) {
        _root += root%10;
        root /= 10;
      }
      root = _root;
    }
    
    printf("%d\n", root);
  }
}

/* 입력값의 자리수가 최대 1000자리임에 유의하자 */