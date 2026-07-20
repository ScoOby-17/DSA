/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            
            ans.push_back(tmp->data);
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
        
        return ans;
    }
};