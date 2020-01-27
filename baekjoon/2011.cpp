#include<cstdio>
#include<cstring>
char cipher[5001];
int dp[5000];
int search(int pos) {
  if (cipher[pos] == 0) {
    return 1;
  }
  if (cipher[pos] == 0x30) {
    return 0;
  }
  if (dp[pos] != -1) {
    return dp[pos];
  }
  
  int ret;
  if (cipher[pos] == 0x31) {
    if (cipher[pos+1] == 0x30) {
      ret = (cipher[pos+1] != 0 ? search(pos+2) : 0);
    }
    else {
      ret = search(pos+1) + (cipher[pos+1] != 0 ? search(pos+2) : 0);
    }
  }
  else if (cipher[pos] == 0x32) {
    if (cipher[pos+1] == 0x30) {
      ret = (cipher[pos+1] != 0 ? search(pos+2) : 0);
    }
    else if (cipher[pos+1] <= 0x36) {
      ret = search(pos+1) + (cipher[pos+1] != 0 ? search(pos+2) : 0);
    }
    else {
      ret = search(pos+1);
    }
  }
  else {
    ret = search(pos+1);
  }
  dp[pos] = ret%1000000;
  return ret%1000000;
}
int main() {
  scanf("%s", cipher);
  memset(dp, -1, 20000);
  printf("%d\n", search(0));
}

/* 0. 1000000으로 나눈 나머지!!!!!!!!!!!!!! */
/* 1. 현재 숫자가 1일 경우, 2일 경우, 나머지일 경우 고려 */
/* 2. 현재 숫자가 0일 경우 경우의 수 없음 */
/* 3. pos+2로 건너 뛸 때 문자열이 이미 끝나지 않았는지 먼저 체크 */
