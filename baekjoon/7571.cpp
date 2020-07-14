#include<cstdio>
#include<cstdlib>

int N, M, x, y;
int xDots[10010], yDots[10010];
int xCnt, yCnt, xDest, yDest, sum;

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=1; i<=N; i++) {
    xDots[i] = yDots[i] = 0;
  }
  
  for (int i=0; i<M; i++) {
    scanf("%d %d", &x, &y);
    
    xDots[x] += 1;
    yDots[y] += 1;
  }
  
  xCnt = yCnt = 0;
  for (int i=1; i<=N; i++) {
    xCnt += xDots[i];
    if (2*xCnt >= M) {
      xDest = i;
      break;
    }
  }
  for (int i=1; i<=N; i++) {
    yCnt += yDots[i];
    if (2*yCnt >= M) {
      yDest = i;
      break;
    }
  }
  
  for (int i=1; i<=N; i++) {
    sum += abs(xDest - i)*xDots[i] + abs(yDest - i)*yDots[i];
  }
  
  printf("%d\n", sum);
}

/*
  처음에는 평균값 근처 지점이 점이 모일 곳이라고 생각했는데, 중간값 근처 지점이 최적인 지점이었다.
*/