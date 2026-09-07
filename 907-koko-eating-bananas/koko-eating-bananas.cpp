class Solution {
public:
    long long calculateHours(vector<int>& piles , int &capacity){
        long long totalTime = 0;
        for(int i=0;i<piles.size();i++){
            totalTime += ceil((double)piles[i]/capacity);
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=0;
        //find range of start and end
        for(int i=0;i<piles.size();i++){
            e = max(e , piles[i]);
        }
        int ans = 1;

        while(s<=e){
            int m = s+(e-s)/2;
            long long totalTime = calculateHours(piles , m);
            if(totalTime <= h){
                ans = m;
                e=m-1;
            }else{
                s=m+1;
            }
        }

        return ans;
    }
};