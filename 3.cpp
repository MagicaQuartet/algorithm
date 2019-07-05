class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        vector<char> window;
        
        for (auto c: s) {            
            int pos = 0;
            for (auto wc: window) {
                if (wc == c) {
                    break;
                }
                pos++;
            }
            
            if (pos < window.size()) {
                if (answer < window.size()) {
                    answer = window.size();
                }
                window.erase(window.begin(), window.begin()+pos+1);
            }
            window.push_back(c);
        }
        
        if (answer < window.size()) {
            answer = window.size();
        }
        
        return answer;
    }
};