#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M, K;
int head[4000010];
int nums[4000010];
int find(int n) {
    if (head[n] == n) {
        return n;
    }
    return head[n] = find(head[n]);
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    memset(head, -1, sizeof(head));
    int min_val = -1;
    int max_val = -1;
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        head[num] = num;
        if (max_val < num) {
            max_val = num;
        }
        if (min_val == -1 || num < min_val) {
            min_val = num;
        }
    }
    int idx = 0;
    for (int i = min_val; i <= max_val; i++) {
        if (head[i] != -1) {
            nums[idx++] = i;
        }
    }
    int max_num = nums[M - 1];
    for (int i = 0; i < K; i++) {
        int num;
        scanf("%d", &num);
        int* ub = upper_bound(nums, nums + M, num);
        int res = find(head[*ub]);
        printf("%d\n", res);
        if (res < max_num) {
            int* resub = upper_bound(nums, nums + M, res);
            head[res] = *resub;
        }
    }
}