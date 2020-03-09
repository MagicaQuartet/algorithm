#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;
int N;
char data[200][200];
void flip(vector<pair<int, int> >& ans, int x, int y) {
  if (data[x][y] == 'U' && data[x][y+1] == 'L') {
    flip(ans, x, y+1);
  }
  else if (data[x][y] == 'R' && data[x][y+1] == 'U') {
    flip(ans, x, y-1);
  }
  else if (data[x][y] == 'R' && data[x][y+1] == 'L') {
    flip(ans, x, y-1);
    flip(ans, x, y+1);
  }
  else if (data[x][y] == 'L') {
    if (data[x+1][y] != 'L') {
      flip(ans, x+1, y);
      data[x+1][y] = data[x+2][y] = 'L';
      data[x+1][y+1] = data[x+2][y+1] = 'R';
      ans.push_back(make_pair(x+2, y+1));
    }
    
    data[x][y] = data[x][y+1] = 'U';
    data[x+1][y] = data[x+1][y+1] = 'D';
    ans.push_back(make_pair(x+1, y+1));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;
  for (int i=0; i<2*N; i++) {
    string s;
    cin >> s;
    for (int j=0; j<2*N; j++) {
      data[i][j] = s[j];
    }
  }
  
  vector<pair<int, int> > ans;
  
  for (int i=0; i<2*N-1; i++) {
    for (int j=0; j<2*N-1; j++) {
      if (data[i][j] == 'L') {
        flip(ans, i, j);
      }
    }
  }
  
  cout << ans.size() << "\n";
  for(auto p : ans) {
    cout << p.first << " " << p.second << "\n";
  }
}

/*
  와 이게 되네....
  
  우선, 위쪽 벽돌을 정렬할 때 아래쪽 벽돌이 영향을 받을 수는 있지만 반대는 성립하지 않는다.
  따라서 벽돌을 정렬시키는 순서를 좌상단->우하단으로 고정해도 된다.
  
  좌상단->우하단 순으로 문양을 순회하다가 L을 만나면 해당 위치의 벽돌을 정렬시키는 flip 함수를 호출한다.
  flip 함수는 답을 저장할 vector와 호출된 지점의 좌표를 인자로 받으며, 하는 일은 다음과 같다.
  
  *flip 함수의 목적은 호출된 지점과 그 아래 행의 벽돌이 UU/DD가 되게 하는 것이다.*
  0) 해당 위치와 다음 위치에 UU가 있을 경우, 아무 것도 해주지 않아도 된다.
  1) 해당 위치와 다음 위치에 UL이 있을 경우, 다음 위치에서 다시 flip 함수를 호출한다.
  2) 해당 위치와 다음 위치에 RU가 있을 경우, 이전 위치에서 flip 함수를 호출한다.
  3) 해당 위치와 다음 위치에 RL이 있을 경우, 이전 위치와 다음 위치에서 flip 함수를 호출한다.
  4) (제일 중요) 해당 위치에 L이 있을 경우, 이제 얘를 뒤집어야 한다.
     4-1) 바로 아래 행에도 L이 있을 경우 그냥 뒤집을 수 있다. data의 값을 수정하고 ans에 돌린 위치를 추가한다.
     4-2) 바로 아래 행에 L이 없을 경우, L이 오도록 만들어야 한다. 바로 아래 행에서 flip 함수를 다시 호출하면 0,1,2,3번 경우 중 하나에 해당되어 세로로 정렬이 될 것이다. 이제 이걸 가로로 돌리면 원래 4번이 호출되었던 지점에서 벽돌을 세로로 뒤집을 수 있다.  
*/