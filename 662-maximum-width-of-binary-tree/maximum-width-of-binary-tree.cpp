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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root , 0});
        int ans = 0;

        while(!q.empty()){
            unsigned long long firstIdx = q.front().second;
            unsigned long long lastIdx = q.back().second;
            ans = max(ans , (int)(lastIdx - firstIdx + 1));  //convert resul size into int from unsigned long long
            int n = q.size();
            
            for(int i=0;i<n;i++){
                auto [currNode , idx] = q.front();
                q.pop();

                if(currNode->left){
                    q.push({currNode->left , idx*2+1});
                }
                if(currNode->right){
                    q.push({currNode->right , idx*2+2});
                }
            }
        }

        return ans;

        // idx*2+1   formula for find left child value from currend index
        // idx*2+1   formula for find right child value from currend index
    }
};