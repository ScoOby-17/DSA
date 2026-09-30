class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int currDepth = 0;
        int ADepth = 0;
        int BDepth = 0;

        for(int i=0;i<seq.length();i++){
            if(seq[i]=='('){
                currDepth++;
                if(ADepth == BDepth){
                    ADepth++;
                    ans.push_back(0);
                }else{
                    BDepth++;
                    ans.push_back(1);
                }
            }else{
                currDepth--;
                if(ADepth > BDepth){
                    ADepth--;
                    ans.push_back(0);
                }else{
                    BDepth--;
                    ans.push_back(1);
                }
            }
        }

        return ans;
    }
};