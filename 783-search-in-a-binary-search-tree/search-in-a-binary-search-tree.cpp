/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root , int val , TreeNode* &node){
        if(root == NULL || node) return;
        if(root->val == val){
            node = root;
            return;
        }

        if(root->val > val){ // search on left
            solve(root->left , val , node);
        }else{
            solve(root->right , val , node);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = NULL;
        solve(root , val , node);
        return node;
    }
};