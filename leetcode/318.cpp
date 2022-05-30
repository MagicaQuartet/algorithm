class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (auto c : words[i]) {
                bits[i] |= (1 << (c - 'a'));
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (bits[i] & bits[j]) {
                    continue;
                }
                int len = words[i].size() * words[j].size();
                if (ans < len) {
                    ans = len;
                }
            }
        }
        return ans;
    }
};