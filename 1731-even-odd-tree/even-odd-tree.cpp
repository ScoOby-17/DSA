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
    void checkEvenLevel(vector<int>level , bool& isValid){
        int prev = level[0];

        if(prev%2!=1){
            isValid = false;
            return;
        }

        for(int i=1;i<level.size();i++){
            int curr = level[i];
            if(curr>prev && curr%2==1){
                prev = curr;
                continue;
            }
            isValid = false;
            return;
        }

        isValid = true;
    }

    void checkOddLevel(vector<int>level , bool& isValid){
        int prev = level[0];

        if(prev%2!=0){
            isValid = false;
            return;
        }

        for(int i=1;i<level.size();i++){
            int curr = level[i];
            if(curr < prev && curr%2==0){
                prev = curr;
                continue;
            }

            isValid = false;
            return;
        }

        isValid = true;
    }


    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>levelValues;
            int n = q.size();

            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();  q.pop();

                levelValues.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            bool isValid;

            if(level%2 == 0) checkEvenLevel(levelValues , isValid);
            if(level%2 == 1) checkOddLevel(levelValues , isValid);

            if(!isValid) return false;
            level++;
        }

        return true;
    }
};