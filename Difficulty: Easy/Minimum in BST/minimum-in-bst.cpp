/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void solve(Node* root , int& ans){
        if(root == NULL) return;
        
        ans = min(root->data , ans);
        //in BST small is always in left side
        solve(root->left , ans);
    }
    int minValue(Node* root) {
        // code here
        int ans = INT_MAX;
        solve(root , ans);
        return ans;
    }
};