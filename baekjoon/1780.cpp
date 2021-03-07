#include<cstdio>
#include<utility>
using namespace std;
#define pipii pair<int, pair<int, int> >
int N;
int board[2200][2200];
pipii divide(int x, int y, int n) {
    if (n == 1) {
        int first = board[x][y] == -1 ? 1 : 0;
        int second = board[x][y] == 0 ? 1 : 0;
        int third = (first || second) ? 0 : 1;
        return make_pair(first, make_pair(second, third));
    }
    int bp1 = n/3;
    int bp2 = n/3*2;
    pipii ret1 = divide(x, y, n/3);
    pipii ret2 = divide(x+bp1, y, n/3);
    pipii ret3 = divide(x+bp2, y, n/3);
    pipii ret4 = divide(x, y+bp1, n/3);
    pipii ret5 = divide(x+bp1, y+bp1, n/3);
    pipii ret6 = divide(x+bp2, y+bp1, n/3);
    pipii ret7 = divide(x, y+bp2, n/3);
    pipii ret8 = divide(x+bp1, y+bp2, n/3);
    pipii ret9 = divide(x+bp2, y+bp2, n/3);
    pipii ret;
    if (!ret1.first && !ret2.first && !ret3.first && !ret4.first && !ret5.first && !ret6.first && !ret7.first && !ret8.first && !ret9.first
        && !ret1.second.first && !ret2.second.first && !ret3.second.first && !ret4.second.first && !ret5.second.first && !ret6.second.first && !ret7.second.first && !ret8.second.first && !ret9.second.first) {
        ret = make_pair(0, make_pair(0, 1));
    }
    else if (!ret1.second.second && !ret2.second.second && !ret3.second.second && !ret4.second.second && !ret5.second.second && !ret6.second.second && !ret7.second.second && !ret8.second.second && !ret9.second.second
            && !ret1.second.first && !ret2.second.first && !ret3.second.first && !ret4.second.first && !ret5.second.first && !ret6.second.first && !ret7.second.first && !ret8.second.first && !ret9.second.first) {
        ret = make_pair(1, make_pair(0, 0));
    }
    else if (!ret1.first && !ret2.first && !ret3.first && !ret4.first && !ret5.first && !ret6.first && !ret7.first && !ret8.first && !ret9.first
            && !ret1.second.second && !ret2.second.second && !ret3.second.second && !ret4.second.second && !ret5.second.second && !ret6.second.second && !ret7.second.second && !ret8.second.second && !ret9.second.second) {
        ret = make_pair(0, make_pair(1, 0));
    }
    else {
        ret = make_pair(ret1.first+ret2.first+ret3.first+ret4.first+ret5.first+ret6.first+ret7.first+ret8.first+ret9.first,
                         make_pair(ret1.second.first+ret2.second.first+ret3.second.first+ret4.second.first+ret5.second.first+ret6.second.first+ret7.second.first+ret8.second.first+ret9.second.first,
                                   ret1.second.second+ret2.second.second+ret3.second.second+ret4.second.second+ret5.second.second+ret6.second.second+ret7.second.second+ret8.second.second+ret9.second.second));
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    pipii ret = divide(0, 0, N);
    printf("%d\n%d\n%d\n", ret.first, ret.second.first, ret.second.second);
}