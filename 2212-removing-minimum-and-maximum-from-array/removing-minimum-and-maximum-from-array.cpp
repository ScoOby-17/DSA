class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        pair<int,int>minPair = {INT_MAX , -1};
        pair<int,int>maxPair = {INT_MIN , -1};
        int n = nums.size();

        for(int i=0;i<n;i++){
            int curr = nums[i];
            if(curr > maxPair.first) { maxPair.first = curr; maxPair.second = i; }
            if(curr < minPair.first) { minPair.first = curr; minPair.second = i; }
        }
        // ans can be 3 possible cases 1->delete form left, 2->delete from right, 3->some form left some form right
        int ans = n;
        ans = min(ans , max(maxPair.second,minPair.second) + 1); //from left
        ans = min(ans , n - min(minPair.second,maxPair.second)); //from right

        int minIdx = min(minPair.second , maxPair.second);
        int maxIdx = max(minPair.second , maxPair.second);
        ans = min(ans , minIdx + 1 + n - maxIdx); //some form left some form right
        return ans;
    }
};