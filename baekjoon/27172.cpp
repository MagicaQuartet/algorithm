#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int N;
int orig[100010];
set<int> nums;
map<int, int> scores;
void check(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i) {
            continue;
        }
        if (nums.count(i) > 0) {
            scores[i]++;
            scores[n]--;
        }
        if (i != n / i && nums.count(n / i) > 0) {
            scores[n / i]++;
            scores[n]--;
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        orig[i] = n;
        nums.insert(n);
    }
    for (auto num : nums) {
        check(num);
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", scores[orig[i]]);
    }
    printf("\n");
}