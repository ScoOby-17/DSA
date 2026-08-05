/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPath(TreeNode*& root , TreeNode*& p , TreeNode*& q , vector<vector<TreeNode*>>&paths , vector<TreeNode*>& path){
        if(root == NULL) return;

        path.push_back(root);
        if(root == p) paths[0] = path;
        if(root == q) paths[1] = path;
        
        getPath(root->left , p , q , paths , path);
        getPath(root->right , p , q , paths , path);

        path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>>paths(2);
        vector<TreeNode*>path;
        getPath(root , p , q , paths , path);

        TreeNode* ans;
        int i=0;
        while(true){
            if(i == paths[0].size() || i == paths[1].size() || paths[1][i] != paths[0][i]){
                ans = paths[0][i-1];
                break;
            }
            i++;
        }
        return ans;
    }
};