class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (idx < i) {
                break;
            }
            idx = max(idx, i + nums[i]);
            if (idx + 1 >= nums.size()) {
                return true;
            }
        }
        return false;
    }
};

/* DP를 활용하면 각 인덱스에서의 도달 가능 여부를 일일이 찾아도 linear time에 가능하다 */
/* 수정: 생각해보니 DP 같은 거 안 쓰고 순회하면서 도달 가능한 최대 인덱스 갱신하고 그 인덱스를 벗어나면 실패 처리 해주면 된다 */
