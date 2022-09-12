#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
int visited[101], arr[101];
int main() {
    int N;
    scanf("%d", &N);
    memset(visited, 0, sizeof(visited));
    stack<int> stk;
    vector<int> nums;
    for (int i = 1; i <= N; i++) {
        scanf("%d", arr + i);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            continue;
        }
        int cur = i;
        while (1) {
            if (visited[cur]) {
                int tmp = 0;
                while (1) {
                    if (stk.empty()) {
                        while (tmp) {
                            nums.pop_back();
                            tmp--;
                        }
                        break;
                    }
                    int top = stk.top();
                    tmp++;
                    nums.push_back(top);
                    stk.pop();
                    if (top == cur) {
                        break;
                    }
                }
                while (!stk.empty()) {
                    stk.pop();
                }
                break;
            }
            visited[cur] = 1;
            stk.push(cur);
            cur = arr[cur];
        }
    }
    sort(nums.begin(), nums.end());
    printf("%d\n", nums.size());
    for (auto i : nums) {
        printf("%d\n", i);
    }
}