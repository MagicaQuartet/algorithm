#include<iostream>
#include<string>
using namespace std;
int N;
char board[66][66];
string divide(int x, int y, int n) {
    if (n == 1) {
        return string(1, board[x][y]);
    }

    int flag = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[x+i][y+j] != board[x][y]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (flag) {
        return string(1, board[x][y]);
    }
    else {
        int bp = n/2;
        string ret1 = divide(x, y, n/2);
        string ret2 = divide(x, y+bp, n/2);
        string ret3 = divide(x+bp, y, n/2);
        string ret4 = divide(x+bp, y+bp, n/2);
        return '(' + ret1 + ret2 + ret3 + ret4 + ')';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        string row;
        cin >> row;
        for (int j=0; j<N; j++) {
            board[i][j] = row[j];
        }
    } 

    string ret = divide(0, 0, N);
    cout << ret << "\n";
}