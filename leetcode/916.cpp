class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ret;
        vector<vector<int> > cnt1(words1.size(), vector<int>(26, 0));
        vector<int> cnt2(26, 0);
        for (int i = 0; i < words1.size(); i++) {
            for (auto c : words1[i]) {
                cnt1[i][c - 'a']++;
            }
        }
        for (auto s2 : words2) {
            vector<int> _cnt2(26, 0);
            for (auto c : s2) {
                _cnt2[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (cnt2[i] < _cnt2[i]) {
                    cnt2[i] = _cnt2[i];
                }
            }
        }
        for (int i = 0; i < words1.size(); i++) {
            bool valid = true;
            for (int j = 0; j < 26; j++) {
                if (cnt1[i][j] < cnt2[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ret.push_back(words1[i]);
            }
        }
        return ret;
    }
};
