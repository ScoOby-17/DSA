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
    pair<int,int> solve(TreeNode* root , int& count){
        if(root == NULL) return {0,0};

        pair<int,int> leftSum = solve(root->left , count);
        pair<int,int> rightSum = solve(root->right , count);

        int totalSum = leftSum.second + rightSum.second + root->val;
        int nodes = leftSum.first + rightSum.first + 1;

        if(totalSum / nodes == root->val) count++;
        return {nodes , totalSum};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        solve(root , count);
        return count;
    }
};