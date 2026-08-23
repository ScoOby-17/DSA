/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(!root) return root;

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                Node* tmp = q.front();
                q.pop();
                
                Node* right = NULL;
                if(i+1 < n) right = q.front();

                if(right){
                    tmp->next = right;
                }

                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
            }
        }

        return root;
    }
};