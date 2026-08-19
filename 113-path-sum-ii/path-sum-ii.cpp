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
    void solve(TreeNode* root, int targetSum , vector<vector<int>>& ans , vector<int>&path , int sum){
        if(!root) return;
        sum += root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL && sum == targetSum){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        solve(root->left , targetSum , ans , path , sum);
        solve(root->right , targetSum , ans , path , sum);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        int sum = 0;
        solve(root , targetSum , ans , path , sum);

        return ans;
    }
};