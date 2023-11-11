#include<cstdio>
using namespace std;
int sudoku[9][9];
int N;
int main() {
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      scanf("%d", &sudoku[i][j]);
    }
  }
  bool ans = true;
  for (int i=0; i<9; i++) {
    int chkr = 0b000000000;
    int chkc = 0b000000000;
    for (int j=0; j<9; j++) {
      int numr = 1 << (sudoku[i][j]-1);
      int numc = 1 << (sudoku[j][i]-1);
      if (chkr & numr || chkc & numc) {
        ans = false;
        break;
      }
      chkr |= numr;
      chkc |= numc;
    }
    if (!ans) {
      break;
    }
  }
  if (!ans) {
    printf("No\n");
    return 0;
  }

  int offsetx[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
  int offsety[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
  for (int idx=0; idx<9; idx++) {
    int chk = 0b000000000;
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        int num = 1 << (sudoku[offsetx[idx]+i][offsety[idx]+j]-1);
        if (chk & num) {
          ans = false;
          break;
        }
        chk |= num;
      }
      if (!ans) {
        break;
      }
    }
  }
  printf("%s\n", ans ? "Yes" : "No");
}
