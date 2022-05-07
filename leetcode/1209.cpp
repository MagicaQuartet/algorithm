class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int> > dq;
        string ans;
        for (auto c : s) {
            if (!dq.empty() && c == dq.back().first && dq.back().second == k - 1) {
                while (!dq.empty() && dq.back().first == c) {
                    dq.pop_back();
                }
            }
            else if (!dq.empty() && c == dq.back().first) {
                dq.push_back(make_pair(c, dq.back().second + 1));
            }
            else {
                dq.push_back(make_pair(c, 1));
            }
        }
        while (!dq.empty()) {
            ans.push_back(dq.front().first);
            dq.pop_front();
        }
        return ans;
    }
};