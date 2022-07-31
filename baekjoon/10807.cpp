#include<cstdio>
#include<cstring>
int cnt[210];
int N, v;
int main() {
    scanf("%d", &N);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        cnt[num + 100]++;
    }
    scanf("%d", &v);
    printf("%d\n", cnt[v + 100]);
}