#include<cstdio>
int cnt[26], max;
char c, ans;
int main() {
  max = 0;
  ans = '?';
  while((c=getchar())!=EOF && c!='\n') {
    cnt[c >= 0x61 ? c-0x61 : c-0x41]++;
  }
  for (int i=0; i<26; i++) {
    if (cnt[i] > max) {
      max = cnt[i];
      ans = 0x41+i;
    }
    else if (cnt[i] == max) {
      ans = '?';
    }
  }
  printf("%c\n", ans);
}