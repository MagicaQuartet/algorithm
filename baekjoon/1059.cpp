#include<cstdio>
#include<algorithm>
using namespace std;
int L, n, S[51];
int main() {
    scanf("%d", &L);
    S[0] = 0;
    for (int i = 1; i <= L; i++) {
        scanf("%d", S + i);
    }
    scanf("%d", &n);
    sort(S + 1, S + L + 1);
    int* it = lower_bound(S + 1, S + L + 1, n);
    int idx = it - S;
    printf("%d\n", (n - S[idx - 1]) * (S[idx] - n) - (S[idx] == n ? 0 : 1));
}
