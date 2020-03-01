#include<cstdio>
int R, C, data[1000][1000], min, minx, miny;
int main() {
  scanf("%d %d", &R, &C);
  min = 1000;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      scanf("%d", &data[i][j]);
    
      if ((i+j)%2 && min > data[i][j]) {
        min = data[i][j];
        minx = i;
        miny = j;
      }
    }
  }
  
  if (R%2) {
    for (int i=0; i<R; i++) {
      for (int j=0; j<C-1; j++) {
        printf("%c", i%2 ? 'L' : 'R');
      }
      
      if (i<R-1) {
        printf("D");
      }
    }
  }
  else if (C%2){
    for (int i=0; i<C; i++) {
      for (int j=0; j<R-1; j++) {
        printf("%c", i%2 ? 'U' : 'D');
      }
      
      if (i<C-1) {
        printf("R");
      }
    }
  }
  else {
    for (int i=0; i<C; i++) {
      if (i == miny-miny%2) {
        for (int j=0; j<R; j++) {
          if (j == minx) {
            if (j < R-1) {
              printf("D");
            }
            else if (i < C-2) {
              printf("R");
            }
          }
          else {
            printf("%c", (j%2==1 ^ (j > minx)) ? 'L' : 'R');
            if (j < R-1) {
              printf("D");
            }
            else if (i < C-2) {
              printf("R");
            }
          }
        }
        i++;
      }
      else {
        char c = (i%2==1 ^ (i > miny)) ? 'U' : 'D';
        for (int j=0; j<R-1; j++) {
          printf("%c", c);
        }
        if (i < C-1) {
          printf("R");
        }
      }
    }
  }
}

/*
  운 좋게 초견클...
  RC가 홀홀/짝홀/홀짝 일 경우에는 그냥 다 돌 수 있다. 문제는 짝짝일 경우.
  이 때, row와 column의 합이 홀수인 곳 중 한 군데만 거르면 나머지 모든 영역을 다 돌 수 있다.
  인덱스의 합이 짝수인 지점을 거르면 무조건 합이 홀수인 한 부분도 지날 수 없게 되기 때문에 이 경우는 고려하지 않아도 된다.
  
  1. 입력을 받을 때 인덱스의 합이 홀수인 지점 중 최솟값을 가지는 부분을 저장해둔다
  2. 해당 지점의 column index가 홀수이거나 짝수인 경우를 나누어 처리한다.
  
  2번에서 롤러코스터의 이동경로를 정하는 방식은 대략 다음과 같다.
  - 최솟값을 가지는 지점을 지나는 column 근처가 아니면 그냥 위아래로 왔다갔다한다.
  - 여기서 근처라 함은 column index가 i일 때 i가 짝수일 때는 [i-1, i]열, 홀수일 때는 [i, i+1]열
  - 해당 column 근처에서는 ㄹ자로 왔다갔다한다. 이 때 이 근처 영역에 들어갈 때는 항상 맨 위 row에서 진입을 하게 되어있다. 즉, 항상 위에서 아래로 ㄹ자 이동
  - 여기서 가장 위/아래 row에서는 적당히 'R'을 넣어주고, 종착점에서는 아무 출력도 하지 않고 등등 자잘한 처리를 추가
  
  ...대략적으로는 이렇다. 약간 머리 안굴러갈때 코딩하듯이 생각나는대로 갖다붙인 느낌의 코드라 일발로 통과할 줄 몰랐는데 다행히 빠뜨린 경우가 없었나보다.
*/