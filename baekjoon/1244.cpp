#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int sw_cnt, sw, st_cnt, st_sex, st_sw;
  vector<int> switches;
  
  scanf("%d", &sw_cnt);
  for (int i=0; i<sw_cnt; i++) {
    scanf("%d", &sw);
    switches.push_back(sw);
  }
  
  scanf("%d", &st_cnt);
  while (st_cnt--) {
    scanf("%d %d", &st_sex, &st_sw);
    
    if (st_sex == 1) {
      for (int i=st_sw; i-1 < sw_cnt; i+=st_sw)
        switches[i-1] = (switches[i-1]+1)%2;
    } else {
      for (int i=0; (st_sw-1)-i >= 0 && (st_sw-1)+i < sw_cnt; i++) {
        if (switches[st_sw-1-i] == switches[st_sw-1+i]) {
          switches[st_sw-1-i] = (switches[st_sw-1-i]+1)%2;
          if (i > 0)
            switches[st_sw-1+i] = (switches[st_sw-1+i]+1)%2;
        }
        else
          break;
      }
    }
  }
  
  int cnt = 0;
  for (int i=0; i<sw_cnt; i++) {
    if (cnt == 20) {
      cnt = 0;
      printf("\n");
    }
    printf("%d ", switches[i]);
    cnt++;
  }
  return 0;
}