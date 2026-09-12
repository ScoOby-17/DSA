/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void findPredecessor(Node* root , int& key , Node* &predecessor){
        if(root == NULL) return;
        
        if(root->data >= key){
            findPredecessor(root->left , key , predecessor);
        }
        if(root->data < key){
            predecessor = root;
            findPredecessor(root->right , key , predecessor);
        }
    }
    
    void findSuccessir(Node* root , int& key , Node* &successor){
        if(root == NULL) return;
        
        if(root->data > key){
            successor = root;
            findSuccessir(root->left , key , successor);
        }
        if(root->data <= key){
            findSuccessir(root->right , key , successor);
        }
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* predecessor = NULL;
        Node* successor = NULL;
        
        findPredecessor(root , key , predecessor);
        findSuccessir(root , key , successor);
        
        return {predecessor , successor};
    }
};