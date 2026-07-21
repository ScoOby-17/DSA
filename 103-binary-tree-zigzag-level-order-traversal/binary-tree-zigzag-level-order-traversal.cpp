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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int level = 0;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>row(size);

            for(int i=0;i<size;i++){
                TreeNode* tmp = q.front();

                if(level%2 == 0){
                    row[i] = tmp->val;
                }else{
                    int idx = size - i - 1;
                    row [idx] = tmp->val;
                }
                
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                q.pop();
            }

            ans.push_back(row);
            level++;
        }

        return ans;
    }
};