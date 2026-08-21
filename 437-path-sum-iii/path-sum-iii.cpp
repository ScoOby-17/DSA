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
    //prefix sum + hashMap approach TC O(n)
    void solve(TreeNode* root, int &targetSum , int& count , unordered_map<long long,int>&mp , long long currSum){
        if(root == NULL)return;

        currSum += root->val;
        if(mp[currSum-targetSum]){
            count += mp[currSum - targetSum];
        }

        mp[currSum]++;

        solve(root->left , targetSum , count , mp , currSum);
        solve(root->right , targetSum , count , mp , currSum);

        mp[currSum]--;  //backtracking
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long , int>mp;
        mp[0]=1;
        long long currSum = 0;
        solve(root , targetSum , count , mp , currSum);

        return count;
    }
};