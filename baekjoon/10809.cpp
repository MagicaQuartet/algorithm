#include<cstdio>
#include<cstring>
int pos[26], p=0;
char c;
int main() {
  memset(pos, -1, 104);
  while((c=getchar())!='\n' && c!=EOF) {
    if (pos[c-97] == -1) {
      pos[c-97] = p;
    }
    p++;
  }
  for (int i=0; i<26; i++) {
    printf("%d ", pos[i]);
  }
}