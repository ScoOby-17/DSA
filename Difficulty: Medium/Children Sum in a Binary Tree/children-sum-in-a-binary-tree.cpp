/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        queue<Node*>q;
        q.push(root);
        // if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            int sum = 0;
            if(curr->left == NULL && curr->right == NULL) continue;

            
            if(curr->left){
                sum += curr->left->data;
                q.push(curr->left);
            }
            if(curr->right){
                sum += curr->right->data;
                q.push(curr->right);
            }
            
            if(sum != curr->data) return false;
        }
        
        return true;
    }
};