#include<cstdio>
#include<cstring>
int cnt[26], length = 0, oddCnt = 0, step = 0;
char str[51], c;
int main() {
  memset(str, 0, 51);
  while((c=getchar())!=EOF && c!='\n') {
    cnt[c-65]++;
    oddCnt = cnt[c-65]%2 == 0 ? oddCnt-1 : oddCnt+1;
    length++;
  }
  
  if (oddCnt > 1) {
    printf("I'm Sorry Hansoo\n");
  } else {
    for (int i=0; i<26; i++) {
      while(cnt[i] > 0) {
        if (cnt[i] == 1) {
          str[(length-1)/2] = 65+i;
          cnt[i]--;
        } else {
          str[step] = str[length - step - 1] = 65+i;
          cnt[i] -= 2;
          step++;
        }
      }
    }
    printf("%s\n", str);
  }
}