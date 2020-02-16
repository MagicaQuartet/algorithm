#include<cstdio>
#include<vector>
#include<algorithm>
int T, W, cache[31][1001], prev, prevCnt, next;
std::vector<int> jadu;
int solve(int idx, int w) {
  if (idx >= jadu.size()) {
    return 0;
  }
  if (cache[w][idx] != -1) {
    return cache[w][idx];
  }
  
  int ret;
  ret = jadu[idx] + ((w==0) ? solve(idx+2, w) : std::max(solve(idx+2, w), solve(idx+1, w-1)));
  cache[w][idx] = ret;
  return ret;
}
int main() {
  scanf("%d %d", &T, &W);
  prev = 1;
  prevCnt = 1;              // T=1일 때 2가 등장하는 경우를 편리하게 처리하기 위해 1로 설정. 이 때문에 결과값에서 1을 빼야함.
  for (int i=0; i<T; i++) {
    scanf("%d", &next);
    if (prev != next) {
      jadu.push_back(prevCnt);
      prev = next;
      prevCnt = 1;
    }
    else {
      prevCnt++;
    }
  }
  jadu.push_back(prevCnt);
  
  for (int i=0; i<=W; i++) {
    for (int j=0; j<jadu.size(); j++) {
      cache[i][j] = -1;
    }
  }
  
  printf("%d\n", solve(0, W)-1);
}

/* 
  자두가 한 나무에서 계속 떨어지고 있는 중에는 위치를 변경할 필요가 없다. 즉, 위치를 변경하는 시점의 후보는 다른 나무에서 자두가 떨어지기 시작할 때이다.
  그래서 우선 연속적으로 한 나무에서 떨어지는 자두의 개수를 순서대로 저장한다. 예제 입력의 경우에는 1 2 2 2가 될 것이다. 이제 이 배열에서 현재 인덱스와 남은 변경 횟수를 인자로 전달하는 함수를 재귀호출하여 답을 얻는다.
  
  그런데, 이 풀이에서는 시작하자마자 2번 나무에서 떨어지는 경우만을 위해 조건문을 하나 더 만들어주어야 했다. 어려운 일은 아니지만 좀 군더더기같아서 항상 1번 나무에서 자두가 1개 떨어진 다음 입력받은 대로 자두가 떨어지는 것으로 상황을 설정했다.
  이렇게 하면 결과값에서 1을 빼주기만 하면 해당 조건문 없이 답을 구할 수 있다.
*/