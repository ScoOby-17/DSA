class Solution {
public:
    long long calculateHours(vector<int>& piles , int capacity){
        long long totalTime = 0;
        for(int i=0;i<piles.size();i++){
            totalTime+= (piles[i] + capacity - 1) / capacity; //works like ciel fn
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxV = INT_MIN;
        for(int i=0;i<n;i++){
            maxV = max(maxV,piles[i]);
        }

        int i=1;
        int j=maxV;
        int ans=1;
        while(i<=j){
            int mid = i+(j-i)/2;
            long long totalTime = calculateHours(piles,mid);
            if(totalTime<=h){
                ans = mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};