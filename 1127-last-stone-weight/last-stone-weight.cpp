class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }

        while(q.size() > 1){
            int first = q.top(); q.pop();
            int sec = q.top(); q.pop();
            int diff = first-sec;
            if(diff!=0) q.push(diff);
        }
         

        if(q.empty()) return 0;
        return q.top();
    }
};