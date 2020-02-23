#include<cstdio>
#include<algorithm>
using namespace std;
int N, data[1000], x;
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", data+i);
  }
  
  sort(data, data+N);
  x = 0;
  for (int i=0; i<N; i++) {
    if (x+1 < data[i]) break;
    else x += data[i];
  }
  printf("%d\n", x+1);
  return 0;
}

/*
  ~이런걸 어떻게 초등학생이 생각하지??~
  x 이하의 수를 모두 만들 수 있다고 가정하자. 이 때 k가 주어지면, k부터 x+k까지의 수도 가능하다.
  이 때 k가 x+1보다 크다면 x+1이 만들 수 없는 양의 정수 중 가장 작은 값이 된다.
  
  이를 이용하여 입력받은 배열을 오름차순 정렬하고 x=0으로 초기화한 후 배열을 순회하며
  x+1이 data[i]보다 작은 지 체크한다. 그렇다면 바로 루프를 탈출하고 그렇지 않다면 x += data[i]를 한 후 반복한다.
  루프를 나온 뒤에 x에 1을 더하면 답이 된다.
*/