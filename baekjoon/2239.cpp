#include<cstdio>
#include<cstring>
int idx[9][9] = {
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {0, 0, 0, 1, 1, 1, 2, 2, 2},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {3, 3, 3, 4, 4, 4, 5, 5, 5},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 6, 7, 7, 7, 8, 8, 8},
    {6, 6, 6, 7, 7, 7, 8, 8, 8}
};
char input[11];
int row[9], col[9], cell[9], sudoku[9][9];
bool solve(int i, int j) {
    if (i >= 9) {
        return true;
    }
    if (j >= 9) {
        return solve(i+1, 0);
    }
    if (sudoku[i][j]) {
        return solve(i, j+1);
    }

    int mask = row[i] | col[j] | cell[idx[i][j]];
    bool ret;
    for (int shift = 1; shift <= 9; shift++) {
        int bit = 1<<shift;
        if (mask & bit) {
            continue;
        }

        row[i] |= bit;
        col[j] |= bit;
        cell[idx[i][j]] |= bit;
        sudoku[i][j] = shift;
        ret = solve(i, j+1);
        if (ret) {
            break;
        }
        row[i] &= ~bit;
        col[j] &= ~bit;
        cell[idx[i][j]] &= ~bit;
        sudoku[i][j] = 0;
    }
    
    return ret;
}
int main() {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(cell, 0, sizeof(cell));
    for (int i=0; i<9; i++) {
        scanf("%s", input);
        for (int j=0; j<9; j++) {
            sudoku[i][j] = input[j]-'0';
            row[i] |= 1<<sudoku[i][j];
            col[j] |= 1<<sudoku[i][j];
            cell[idx[i][j]] |= 1<<sudoku[i][j]; 
        }
    }
    solve(0, 0);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
}