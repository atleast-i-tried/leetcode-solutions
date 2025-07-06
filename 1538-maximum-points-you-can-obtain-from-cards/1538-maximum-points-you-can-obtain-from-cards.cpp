class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // basically we need to think of it as a pipe, remove the defected part

        int right = 0, left = 0;
        int minScore = INT_MAX;
        int totalSum = 0, score = 0;
        int size = cardPoints.size() - k;

        for(int i: cardPoints) totalSum += i;

        for(right = 0; right < cardPoints.size(); right++) {

            score += cardPoints[right];

            if((right - left + 1) == size) {
                minScore = min(score, minScore);
                score -= cardPoints[left];
                left++;
            }
        }
        return k == cardPoints.size() ? totalSum : totalSum - minScore;
    }
};