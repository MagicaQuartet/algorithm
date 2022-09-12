class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int lhs = 0;
        int rhs = tokens.size() - 1;
        int score = 0;
        while (lhs <= rhs) {
            if (power < tokens[lhs]) {
                if (score == 0 || rhs - 1 <= lhs) {
                    break;
                }
                power += tokens[rhs--];
                score--;
            }
            else {
                power -= tokens[lhs++];
                score++;
            }
        }
        return score;
    }
};