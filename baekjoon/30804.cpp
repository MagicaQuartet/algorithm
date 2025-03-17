#include<cstdio>
#include<cstring>
using namespace std;
int N;
int nums[200010];
int cnt[10];
int used[2];
int main() {
    scanf("%d", &N);
    memset(cnt, 0, sizeof(cnt));
    memset(used, -1, sizeof(used));
    int ans = 0;
    int tmp = 0;
    int lhs = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
        if (used[0] == -1) {
            used[0] = nums[i];
            cnt[nums[i]]++;
            tmp++;
            lhs = i;
        }
        else if (used[0] != nums[i] && used[1] == -1) {
            used[1] = nums[i];
            cnt[nums[i]]++;
            tmp++;
        }
        else if (used[0] == nums[i] || used[1] == nums[i]) {
            cnt[nums[i]]++;
            tmp++;
        }
        else {
            if (ans < tmp) {
                ans = tmp;
            }
            for (int j = lhs; j <= i; j++) {
                cnt[nums[j]]--;
                tmp--;
                if (cnt[nums[j]] == 0) {
                    lhs = j + 1;
                    if (used[0] == nums[j]) {
                        used[0] = nums[i];
                    }
                    else {
                        used[1] = nums[i];
                    }
                    break;
                }
            }
            cnt[nums[i]]++;
            tmp++;
        }
    }
    if (ans < tmp) {
        ans = tmp;
    }
    printf("%d\n", ans);
}