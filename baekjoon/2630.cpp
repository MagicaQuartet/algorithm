#include<cstdio>
#include<utility>
using namespace std;
#define pii pair<int, int>
int N;
int board[130][130];
pii divide(int x, int y, int n) {
    if (n == 1) {
        return board[x][y] ? make_pair(0, 1) : make_pair(1, 0);
    }
    int midx = x + (n/2);
    int midy = y + (n/2);
    pii ret1 = divide(x, y, n/2);
    pii ret2 = divide(midx, y, n/2);
    pii ret3 = divide(x, midy, n/2);
    pii ret4 = divide(midx, midy, n/2);

    if (ret1.first == 0 && ret2.first == 0 && ret3.first == 0 && ret4.first == 0) {
        return make_pair(0, 1);
    }
    else if (ret1.second == 0 && ret2.second == 0 && ret3.second == 0 && ret4.second == 0) {
        return make_pair(1, 0);
    }
    else {
        return make_pair(ret1.first+ret2.first+ret3.first+ret4.first, ret1.second+ret2.second+ret3.second+ret4.second);
    }
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    pii ret = divide(0, 0, N);
    printf("%d\n%d\n", ret.first, ret.second);
}