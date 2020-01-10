#include<cstdio>
int dec, tw, hex, ret10, ret12, ret16;
int main() {
  for (int i=2992; i<10000; i++) {
    dec = tw = hex = i;
    ret10 = ret12 = ret16 = 0;
    while (dec) {
      ret10 += dec%10;
      dec /= 10;
    }
    while (tw) {
      ret12 += tw%12;
      tw /= 12;
    }
    while (hex) {
      ret16 += hex%16;
      hex /= 16;
    }
    if (ret10 == ret12 && ret12 == ret16) {
      printf("%d\n", i);
    }
  }
}