#include<cstdio>
#include<cstring>
using namespace std;
char s[22];
int main() {
  memset(s, 0, 22);
  while(1) {
    char prev = 0;
    int prevCnt = 0, vowelCnt = 0, consonantCnt = 0;
    bool vowel = false, acceptable = true;
    scanf("%s", s);
    
    if (!strcmp(s, "end")) {
      printf("end!");
      break;
    }
    
    for (int i=0; s[i] != 0; i++) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        vowel = true;
        vowelCnt++;
        consonantCnt = 0;
      }
      else {
        vowelCnt = 0;
        consonantCnt++;
      }
      
      if (prev == s[i]) {
        prevCnt++;
      }
      else {
        prev = s[i];
        prevCnt = 1;
      }
      
      if (vowelCnt == 3 || consonantCnt == 3 || (prevCnt == 2 && prev != 'e' && prev != 'o') || prevCnt == 3) {
        acceptable = false;
        break;
      }
    }
    printf("<%s> is %s.\n", s, vowel && acceptable ? "acceptable" : "not acceptable");
    memset(s, 0, 22);
  }
}