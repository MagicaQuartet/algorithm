class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        int pos = 0;
        int len = s.size();
        
        for (int i=0; i<len; i++) {
            int palindrome1 = findPalindrome(s, i, i);
            int palindrome2 = findPalindrome(s, i, i+1);
            
            int _max = palindrome1 > palindrome2 ? palindrome1 : palindrome2;
            
            if (max < _max) {
                max = _max;
                pos = i-floor((max-1)/2);
            }
        }
        
        return string(s, pos, max);
    }
    
    int findPalindrome(string s, int head, int tail) {
        while (head >= 0 && tail < s.size() && s[head]==s[tail]) {
            head--;
            tail++;
        }
        return tail-head-1;
    }
};

/* DP를 이용하여 작은 palindrome부터 시작해서 큰 palindrome을 찾는다. 단, dp를 쓰려고 2차원 배열을 만드는 멍청한 짓을 했었는데 그럴 필요 없다. */