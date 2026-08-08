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
    void solve(TreeNode* root , int &val , int &sum){
        if(root == NULL){
            // cout << sum  <<"  "<< val << endl;
            return;
        }

        val *= 10;
        val += root->val;
        if(root->left == NULL && root->right == NULL) {
            sum+=val;
            val /= 10;
            return;
        }
        solve(root->left , val , sum);
        solve(root->right , val , sum);
        val /= 10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int val = 0;
        solve(root , val , sum);
        return sum;
    }
};