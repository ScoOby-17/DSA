/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int& k, unordered_map<int, int>&mp, bool& ans) {
        if (root == NULL || ans)
            return;

        int diff = k - root->val;
        if (mp.count(diff) && mp[diff] > 0) {
            ans = true;
            return;
        }

        mp[root->val]++;

        solve(root->left, k, mp, ans);
        solve(root->right, k, mp, ans);
        
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        unordered_map<int, int> mp;
        solve(root, k, mp, ans);
        return ans;
    }
};