class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        vector<int>ans;
        int n=arr.size();
        stack<int>s;
        
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()>=arr[i]){
                s.pop();
            }
            
            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};