class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int n = candyType.size();
        int advice = n/2;
        int canEat = 0;
        int i=0;
        while(canEat < advice && n > i){
            if(i==0) {
                canEat++;
            }else{
                if(candyType[i] != candyType[i-1]) canEat++;
            }
            i++;
        }
        return canEat;
    }
};