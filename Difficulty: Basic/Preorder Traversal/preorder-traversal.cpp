/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    
    void traverse(Node* root , vector<int>& ans){
        if(root == NULL)return ;
        ans.push_back(root->data);
        traverse(root->left , ans);
        traverse(root->right , ans);
    }
    
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ans;
        traverse(root , ans);
        return ans;
    }
};