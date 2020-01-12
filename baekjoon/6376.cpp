#include<cstdio>
int main() {
  int factorial[] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  double prev = 1;
  printf("n e\n- -----------\n0 1\n");
  for (int i=0; i<9; i++) {
    printf(i==0 ? "%d %.0f\n" : i==1 ? "%d %.1f\n" : "%d %.9f\n", i+1, prev = prev+1.0/factorial[i]);
  }
}