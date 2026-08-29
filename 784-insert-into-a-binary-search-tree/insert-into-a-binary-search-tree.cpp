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
    // approcah ---> always insert in leaf node
    void solve(TreeNode* root , int val){
        if(root == NULL) return;

        int curr = root->val;
        if(curr < val){ // go on right side
            if(root->right) solve(root->right , val);
            else {
                TreeNode* tmp = new TreeNode(val);
                root->right = tmp; return;
            }
        }
        if(curr > val){ // go on left side
            if(root->left) solve(root->left , val);
            else {
                TreeNode* tmp = new TreeNode(val);
                root->left = tmp; return;
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) root = new TreeNode(val);
        solve(root , val);
        return root;
    }
};