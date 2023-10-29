#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> A;
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    int i = 0;
    int j = 0;
    int ans = 1;
    while (j < N) {
        if (i > j) {
            j = i;
            continue;
        }
        if (A[j] - A[i] >= M) {
            i++;
            continue;
        }
        ans = ans < j - i + 1 ? j - i + 1 : ans;
        j++;
    }
    printf("%d\n", ans);
}