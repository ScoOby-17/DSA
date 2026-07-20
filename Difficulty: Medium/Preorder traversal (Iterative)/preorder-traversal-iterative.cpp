/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ans;
        stack<Node*>s;
        if(root == NULL) return ans;  //edge case
        s.push(root);
        
        while(!s.empty()){
            Node* tmp = s.top();
            s.pop();
            ans.push_back(tmp->data);
            
            if(tmp->right != NULL){
                s.push(tmp->right);
            }
            if(tmp->left != NULL){
                s.push(tmp->left);
            }
        }
        
        return ans;
    }
};