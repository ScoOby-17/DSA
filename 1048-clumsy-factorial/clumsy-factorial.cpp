class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        int op=0;
        st.push(n);
        n--;
        while(n>0){
            if(op == 0){
                int Top = st.top();
                st.pop();
                int val = Top*n;
                st.push(val);
            }else if(op == 1){
                int Top = st.top();
                st.pop();
                int val = Top/n;
                st.push(val);
            }else if(op == 2){
                st.push(n);
            }else{
                st.push(-n);
            }

            n--,op++;
            op = op%4;
        }

        int ans = 0;
        while(!st.empty()){
            int Top = st.top();
            st.pop();
            ans += Top;
        }

        return ans;
    }
};