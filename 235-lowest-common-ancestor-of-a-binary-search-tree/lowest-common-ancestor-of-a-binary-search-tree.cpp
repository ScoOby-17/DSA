/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findPath(TreeNode* root , int& data , vector<TreeNode*>&path , vector<TreeNode*>&nodePath){
        if(root == NULL || nodePath.size()) return;

        path.push_back(root);
        if(root->val == data){
            nodePath = path;
            return;
        }

        //BST traversel
        if(root->val > data) findPath(root->left , data , path , nodePath);
        if(root->val < data) findPath(root->right , data , path , nodePath);

        path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pathOfP;
        vector<TreeNode*>pathOfQ; 
        vector<TreeNode*>path;

        findPath(root , p->val , path , pathOfP);
        path.clear();
        findPath(root , q->val , path , pathOfQ);

        int lengthOfP = pathOfP.size();
        int lengthOfQ = pathOfQ.size();
        int n = min(lengthOfP , lengthOfQ);

        TreeNode* ans = NULL;
        for(int i=0;i<n;i++){
            if(pathOfP[i]->val == pathOfQ[i]->val) ans = pathOfP[i];
            else break;
        }

        return ans;
    }
};