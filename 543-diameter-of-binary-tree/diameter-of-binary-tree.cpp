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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int length = 0;

        while(!q.empty()){
            int size = q.size();
            length++;

            for(int i=0;i<size;i++){
                TreeNode* tmp = q.front();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                q.pop();
            }

        }

        return length;
    }

    void solve(TreeNode* root , int& diameter){
        if(root == NULL) return;

        //left height & right height
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter , leftHeight + rightHeight);

        if(root->left) solve(root->left , diameter);
        if(root->right) solve(root->right , diameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int diameter = 0;
        solve(root , diameter);
        return diameter;
    }
};