#include<cstdio>

int a, b;
int arr[21];

int main() {
  for (int i=1; i<=20; i++) {
    arr[i] = i;
  }
  
  for (int i=0; i<10; i++) {
    scanf("%d %d", &a, &b);
    
    for (int j=0; j<(b-a+1)/2; j++) {
      int temp = arr[b-j];
      arr[b-j] = arr[a+j];
      arr[a+j] = temp;
    }
  }
  
  for (int i=1; i<=20; i++) {
    printf("%d ", arr[i]);
  }
}