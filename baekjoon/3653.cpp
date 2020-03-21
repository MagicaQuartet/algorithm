#include<cstdio>
#include<cstring>
int T, N, M, pick, bitree[200010], position[100010];

void add(int pos, int diff) {
  while (pos <= N+M) {
    bitree[pos] += diff;
    pos += (pos & -pos);
  }
}

int query(int pos) {
  int ret = 0;
  while (pos > 0) {
    ret += bitree[pos];
    pos &= (pos-1);
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  
  while (T--) {
    scanf("%d %d", &N, &M);
    memset(bitree, 0, sizeof(bitree));
    
    for (int i=1; i<=N; i++) {
      position[i] = M+i;
      add(M+i, 1);
    }
    
    for (int i=1; i<=M; i++) {
      scanf("%d", &pick);
      
      printf("%d ", query(position[pick]-1));
      add(position[pick], -1);
      add(M-i+1, 1);
      position[pick] = M-i+1;
    }
    
    printf("\n");
  }
}

/*
  BIT를 다음과 같이 구성할 것이다. (전체 크기를 N+M으로 잡는 이유는 후술)
  bitree[i] : (N+M+1-i)층에 영화가 쌓여있으면 1, 없으면 0 (i := 1, 2, 3, ..., N+M)
  
  또한 각 영화의 위치를 position 배열에 저장한다.
  position[j] : j번 영화의 현재 위치.
  처음에는 position[1] = M+1, ..., position[N] = M+N 로 초기화.
  
  그리고 k번째로 본 영화를 맨 위에 놓을 때 그 영화의 높이는 (N+k) 로 한다.
  
  p번 영화보다 위에 있는 영화의 갯수가 query(position[p]-1)임을 고려하고 적절히 bitree를 갱신해주면 답을 구할 수 있다.
*/