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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void findNode(TreeNode* root){ //inorder traversal
        if(root == NULL) return ;
        
        findNode(root->left);

        if(prev->val > root->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;

        findNode(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        findNode(root);

        if(first && last){
            swap(first->val , last->val);
        }else{
            swap(first->val , middle->val);
        }
    }
};