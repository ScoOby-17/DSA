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
    TreeNode* findRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findRight(root->right);
    }

    TreeNode* solveFn(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        // we can here only when left and right not NULL
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findRight(root->left); //delete kren wali node ke left node ka sabse bottom right node
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            root = solveFn(root);
            return root;
        }

        TreeNode* dummyRoot = root;
        while(root){
            if(root->val > key){ //delete data on left
                if(root->left && root->left->val == key){
                    root->left = solveFn(root->left);
                    break;
                }else{
                    root = root->left; //go on left
                }
            }else{ // delete data on right
                if(root->right && root->right->val == key){
                    root->right = solveFn(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }

        return dummyRoot;
    }
};