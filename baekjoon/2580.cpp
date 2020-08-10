#include<cstdio>
#include<cstring>
#include<vector>
#define pii pair<int, int>
using namespace std;

int sudoku[9][9];
int row[9][10];
int col[9][10];
int box[9][10];

int solve(const vector<pii >& blank, int idx) {
  if (idx >= blank.size()) {
    for (int i=0; i<9; i++) {
      for (int j=0; j<9; j++) {
        printf("%d ", sudoku[i][j]);
      }
      printf("\n");
    }
    return 0;
  }
  
  int ret = -1;
  int r = blank[idx].first;
  int c = blank[idx].second;

  for (int i=1; i<=9; i++) {
    if (row[r][i] || col[c][i] || box[3*(r/3)+c/3][i]) {
      continue;
    }

    row[r][i] = col[c][i] = box[3*(r/3)+c/3][i] = 1;
    sudoku[r][c] = i;
    ret = solve(blank, idx+1);
    if (!ret) { break; }
    sudoku[r][c] = 0;
    row[r][i] = col[c][i] = box[3*(r/3)+c/3][i] = 0;
  }
  return ret;
}

int main() {
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  memset(box, 0, sizeof(box));
  vector<pii > blank;

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      int num;
      scanf("%d", &num);
      sudoku[i][j] = num;

      if (num) {
        row[i][num] = 1;
        col[j][num] = 1;
        box[3*(i/3)+j/3][num] = 1;
      }
      else {
        blank.push_back({i, j});
      }
    }
  }

  solve(blank, 0);
}