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
    int maxValIndex(vector<int>& nums , int l , int r){
        int maxVal = INT_MIN;
        int maxValIdx = -1;
        for(int i=l;i<=r;i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxValIdx = i;
            }
        }
        return maxValIdx;
    }

    TreeNode* buildTree(vector<int>& nums , int l , int r){
        if(l>r) return NULL; //edge case
        int idx = maxValIndex(nums , l , r);
        TreeNode* root = new TreeNode(nums[idx]);

        root->left = buildTree(nums , l , idx-1);
        root->right = buildTree(nums , idx+1 , r);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = buildTree(nums , 0 , nums.size()-1);
        return root;
    }
};