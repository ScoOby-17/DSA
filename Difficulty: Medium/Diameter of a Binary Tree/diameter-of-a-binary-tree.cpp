/*Structure of tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    int solve(Node* root , int& ans){
        if(root == NULL) return 0;
        
        int leftHeight = solve(root->left , ans);
        int rightHeight = solve(root->right , ans);
        
        ans = max(ans , leftHeight+rightHeight);
        
        return 1+max(leftHeight , rightHeight);
    }
    
    int diameter(Node* root) {
        // code here
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};