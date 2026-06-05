class Solution {
  public:
    int canReadBook(vector<int> &arr, int k, int pages){
        int pageStudent=0;
        int student=1;
        for(int i=0;i<arr.size();i++){
            if(pageStudent + arr[i] <= pages){
                pageStudent+=arr[i];
            }else{
                student++;
                pageStudent=arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        
        int s=0;
        int e=0;
        for(int i=0;i<arr.size();i++){
            s=max(s,arr[i]);
            e+=arr[i];
        }
        
        int ans=0;
        
        while(s<=e){
            int m=s+(e-s)/2;
            int studentNeed = canReadBook(arr,k,m);
            if(studentNeed <= k){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};