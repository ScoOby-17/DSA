/* Structure of a Binary Tree Node
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
    void solve(Node*root ,int& k ,bool& gethighest ,bool& getAns ,int& count ,int& ans){
        if(root==NULL || getAns) return ;
        solve(root->right , k , gethighest , getAns , count , ans);
        
        //logic
        if(gethighest || root->right==NULL){
            count++;
            gethighest = true;
        }
        if(k==count){
            ans = root->data;
            getAns = true;
            return;
        }
        
        solve(root->left , k , gethighest , getAns , count , ans);
    }
    
    int kthLargest(Node *root, int k) {
        // code here
        bool gethighest = false , getAns = false;
        int count = 0;
        int ans;
        solve(root , k , gethighest , getAns , count , ans);
        return ans;
    }
};