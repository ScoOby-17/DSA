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
    bool isSymmetric(TreeNode* root) {
        vector<vector<TreeNode*>>arr;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*>level;

            for(int i=0;i<size;i++){
                TreeNode* tmp = q.front();
                level.push_back(tmp);
                q.pop();

                if(tmp == NULL)continue;
    
                q.push(tmp->left);
                q.push(tmp->right); 
                
            }
            arr.push_back(level);
        }

        for(auto level : arr){
            int i=0;
            int j=level.size()-1;

            while(i<j){
                if(level[i] == NULL && level[j] == NULL){
                    i++,j--;
                    continue;
                }
                if(level[i]== NULL || level[j] == NULL) return false;
                if(level[i]->val != level[j]->val) return false;
                i++,j--;
            }
        }
    
        return true;
    }
};