class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int> > stk;
        stk.push(make_pair('*', -1));
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (stk.top().first == '(' && s[i] == ')') {
                stk.pop();
                int len = i - stk.top().second;
                if (ans < len) {
                    ans = len;
                }
            }
            else {
                stk.push(make_pair(s[i], i));
            }
        }
        return ans;
    }
};