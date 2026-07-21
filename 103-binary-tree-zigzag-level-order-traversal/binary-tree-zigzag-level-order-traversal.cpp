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
            vector<int>row;

            for(int i=0;i<size;i++){
                TreeNode* tmp = q.front();
                row.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                q.pop();
            }

            if(level%2 == 0){
                ans.push_back(row);
            }else{
                reverse(row.begin() , row.end());
                ans.push_back(row);
            }
            level++;
        }

        return ans;
    }
};