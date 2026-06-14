class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0 , rightSum=0;
        int rightIdx = cardPoints.size() -1;
        int maxSum = 0;

        for(int i=0;i<k;i++) leftSum += cardPoints[i];
        maxSum = leftSum;
 
        for(int i=k-1;i>=0;i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIdx--];
            int sum = leftSum + rightSum;
            maxSum = max(maxSum , sum);
        }

        return maxSum;
    }
};