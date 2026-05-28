class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int plyrPtr = 0;
        int tnrPtr = 0;

        while(plyrPtr<players.size() && tnrPtr<trainers.size()){
            if(players[plyrPtr] <= trainers[tnrPtr]){
                plyrPtr++;
                tnrPtr++;
            }else{
                tnrPtr++;
            }
        }
        
        return plyrPtr;
    }
};