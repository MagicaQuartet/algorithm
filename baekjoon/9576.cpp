#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int T, N, M, cnt;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &M);
    vector<int> book(N, 0);
    vector<pair<int, int> > student(M, make_pair(0, 0));
    
    for (int i=0; i<M; i++) {
      scanf("%d %d", &student[i].second, &student[i].first);
    }
    
    sort(student.begin(), student.end());
    
    cnt = 0;
    for (auto p : student) {
      bool available = false;
      for (int i=p.second-1; i<p.first; i++) {
        if (book[i] == 0) {
          book[i] = 1;
          available = true;
          break;
        }
      }
      
      if (available) cnt++;
    }
    
    printf("%d\n", cnt);
  }
}

/*
  (b의 값이 작은 순 -> a의 값이 작은 순) 으로 정렬하여 각 경우에 줄 수 있는 가장 낮은 번호의 책을 배정하였다.
  회의실 배정 문제랑 동일한 아이디어.
  
  근데 질문 게시판 봐도 그렇고 알고리즘 분류 봐도 그렇고 solved.ac 티어도 그렇고...이렇게 푸는 문제가 아닌가??
*/