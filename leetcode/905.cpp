class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> answer;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]%2 == 0) {
                answer.push_back(nums[i]);
                nums[i] = 0;
            }
        }
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                continue;   
            }
            answer.push_back(nums[i]);
        }
        return answer;
    }
};
