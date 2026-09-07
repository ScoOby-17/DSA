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
    void solve(TreeNode* root , int k , bool& getSamllest , bool& getAns ,int& count, int& ans){
        if(getAns || root==NULL) return;

        solve(root->left , k , getSamllest , getAns , count , ans);

        if(root->left==NULL || getSamllest){
            count++;
            getSamllest = true;
        }
        if(count == k){
            ans = root->val;
            getAns = true;
        }

        solve(root->right , k , getSamllest , getAns , count , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        bool getSamllest = false , getAns = false;
        int count = 0;
        solve(root , k , getSamllest , getAns , count , ans);
        return ans;
    }
};