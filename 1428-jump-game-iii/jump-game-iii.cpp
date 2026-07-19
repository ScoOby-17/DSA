class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>isVisited(n , false); // to store we check this index or not
        queue<int>q; //store index

        q.push(start);
        isVisited[start] = 1;

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0) return true;

            int right = arr[idx] + idx;
            int left = idx - arr[idx];

            if(right < n && !isVisited[right]){
                isVisited[right] = 1;
                q.push(right);
            }
            if(left >= 0 && !isVisited[left]){
                isVisited[left] = 1;
                q.push(left);
            }
        }

        return false;
    }
};