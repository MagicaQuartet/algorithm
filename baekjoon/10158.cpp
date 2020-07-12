#include<cstdio>

int w, h, p, q, t;
int deltap, deltaq;
int x, y;

int main() {
  scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);
  
  deltap = t%(2*w);
  deltaq = t%(2*h);
  
  if (p+deltap <= w) {
    x = p+deltap;
  }
  else if (p+deltap <= 2*w) {
    x = 2*w - (p+deltap);
  }
  else {
    x = (p+deltap) - 2*w;
  }
  
  if (q+deltaq <= h) {
    y = q+deltaq;
  }
  else if (q+deltaq <= 2*h) {
    y = 2*h - (q+deltaq);
  }
  else {
    y = (q+deltaq) - 2*h;
  }
  
  printf("%d %d\n", x, y);
}

/*
  대각선으로 이동하는 것은 결국 x, y값이 왔다갔다 하는 거니까 현혹되지 말자
*/