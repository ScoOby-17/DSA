/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* root , vector<int>& ans){
        if(root == NULL) return;
        traverse(root->left , ans);
        traverse(root->right , ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        traverse(root , ans);
        return ans;
    }
};