#include<cstdio>
int A, B;
int main() {
  scanf("%d %d", &A, &B);
  printf("%s\n", A < B ? "<" : A > B ? ">" : "==");
}