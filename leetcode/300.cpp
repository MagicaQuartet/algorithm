class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (auto n : nums) {
            vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), n);
            if (it == lis.end()) {
                lis.push_back(n);
            }
            else {
                *it = n;
            }
        }
        return lis.size();
    }
};