class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;
        for (auto c: s) {
            if (c != '#') {
                ss.push(c);
            }
            else if (!ss.empty()) {
                ss.pop();
            }
        }
        for (auto c: t) {
            if (c != '#') {
                tt.push(c);
            }
            else if (!tt.empty()) {
                tt.pop();
            }
        }
        while (!ss.empty() && !tt.empty()) {
            if (ss.top() != tt.top()) {
                return false;
            }
            ss.pop();
            tt.pop();
        }
        return ss.empty() && tt.empty();
    }
};
