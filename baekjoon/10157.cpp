#include<cstdio>

int C, R, K, step, x, y;

int main() {
  scanf("%d %d %d", &R, &C, &K);
  
  if (C*R < K) {
    printf("0\n");
  }
  else {
    step = x = y = 1;
    
    while(K >= step + 2*(C+R-2) && C > 2 && R > 2) {
      step += 2*(C+R-2);
      C -= 2;
      R -= 2;
      x += 1;
      y += 1;
    }
    
    if (K <= step + (C-1)) { 
      y += K - step;
    }
    else if (K <= step + (C-1) + (R-1)) {
      x += K - (step + (C-1));
      y += C-1;
    }
    else if (K <= step + 2*(C-1) + (R-1)) {
      x += R-1;
      y += (C-1) - (K - (step + (C-1) + (R-1)));
    }
    else {
      x += (R-1) - (K - (step + 2*(C-1) + (R-1)));
    }
    
    printf("%d %d\n", x, y);
  }
}

/*
  단순함에 비해 각 경우를 나누는게 복잡해졌다. 더 간단하게 표현할 수 있을까?
*/