class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>leftAssign;
        vector<int>rightAssign(n,1);

        //leftAssign
        int leftCandy = 0;
        for(int i=0;i<n;i++){
            if(i==0){
                leftCandy++;
                leftAssign.push_back(leftCandy);
                continue;
            }
            if(ratings[i]>ratings[i-1]){
                leftCandy++;
                leftAssign.push_back(leftCandy);
            }else{
                leftCandy = 1;
                leftAssign.push_back(leftCandy);
            }
        }
        //rightAssign
        int rightCandy=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                rightCandy++;
                rightAssign.push_back(rightCandy);
                continue;
            }
            if(ratings[i]>ratings[i+1]){
                rightCandy++;
                rightAssign[i] = rightCandy;
            }else{
                rightCandy=1;
                rightAssign[i] = rightCandy;
            }
        }

        int totalCandy=0;
        for(int i=0;i<n;i++){
            int maxCandy = max(leftAssign[i],rightAssign[i]);
            totalCandy+=maxCandy;
        }

        return totalCandy;
    }
};