/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void solve(Node* root , int& k , int& ans){
        if(root==NULL || k == ans) return;
        
        if(root->data == k){
            ans = k;
            return;
        }
        
        if(root->data > k){
            solve(root->left , k , ans);
        }else{
            ans = root->data;
            solve(root->right , k , ans);
        }
    }
    int findMaxFork(Node* root, int k) {
        // code here
        int ans=-1;
        solve(root , k , ans);
        return ans;
    }
};