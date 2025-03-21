#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N, M, K;
int candy[30010];
int head_[30010][3]; // locality에 대해 언급하는 글이 많아서 온몸 비틀기함... 가독성에 대해선 미안하다 (head / head_cnt / head_candy)
int dp[30010][3010]; // 근데 왠지 온몸비틀기 할 것 없이 dp 적용으로 충분히 가능했을 것 같다.. 미안하다
map<int, int> skip_to; // head cnt -> idx
struct cmp {
    bool operator()(int a, int b) {
        if (head_[a][1] != head_[b][1]) {
            return head_[a][1] > head_[b][1];
        }
        return head_[a][2] > head_[b][2];
    }
} mycmp;
int find_head(int x) {
    if (head_[x][0] <= 0) {
        head_[x][0] = x;
    }
    if (head_[x][0] == x) {
        return x;
    }
    return head_[x][0] = find_head(head_[x][0]);
}
void merge(int a, int b) {
    int a_head = find_head(a);
    int b_head = find_head(b);
    if (a_head < b_head) {
        head_[b_head][0] = a_head;
    }
    else {
        head_[a_head][0] = b_head;
    }
}
int solve(vector<int>& pick_head, int cur_idx, int picked) {
    if (cur_idx >= pick_head.size()) {
        return 0;
    }
    if (picked >= K) {
        return 0;
    }
    if (dp[cur_idx][picked] != -1) {
        return dp[cur_idx][picked];
    }
    int _ans1 = 0;
    map<int, int>::iterator it = skip_to.find(head_[pick_head[cur_idx]][1]);
    if (it != skip_to.end()) {
        _ans1 = solve(pick_head, it->second, picked);
    }
    int _ans2 = 0;
    if (picked + head_[pick_head[cur_idx]][1] < K) {
        _ans2 = solve(pick_head, cur_idx + 1, picked + head_[pick_head[cur_idx]][1]) + head_[pick_head[cur_idx]][2];
    }
    return dp[cur_idx][picked] = _ans1 > _ans2 ? _ans1 : _ans2;
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    memset(head_, 0, sizeof(head_));
    memset(dp, -1, sizeof(dp));
    // 사탕 수
    for (int i = 1; i <= N; i++) {
        scanf("%d", candy + i);
    }
    // 친구 관계 disjoint set 생성
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(a, b);
    }
    // disjoint set 별 인원 및 사탕 수 계산
    vector<int> pick_head;
    for (int i = 1; i <= N; i++) {
        int i_head = find_head(i);
        head_[i_head][2] += candy[i];
        head_[i_head][1]++;
        if (i_head == i) {
            pick_head.push_back(i);
        }
    }
    // 인원 수 및 사탕 수에 따라 disjoint set 정렬
    sort(pick_head.begin(), pick_head.end(), mycmp);
    // 순회 시 인원 수가 적은 disjoint setd으로 바로 넘어가기 위한 skip_to 생성
    int prev = pick_head[0];
    for (int i = 1; i < pick_head.size(); i++) {
        if (head_[pick_head[i]][1] == head_[prev][1]) {
            continue;
        }
        skip_to[head_[prev][1]] = i;
        prev = pick_head[i];
    }

    printf("%d\n", solve(pick_head, 0, 0));
}
