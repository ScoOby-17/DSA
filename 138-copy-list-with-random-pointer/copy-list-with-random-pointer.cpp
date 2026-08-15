/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dumy = new Node(-1);
        Node* prev = dumy;
        Node* tmp = head;
        int idx = 1;
        unordered_map<Node*,int>mp;

        //traverse
        while(tmp){
            mp[tmp] = idx++;  // maping reference and index
            Node* curr = new Node(tmp->val);
            prev->next = curr;
            prev = curr;
            tmp = tmp->next;
        }

        tmp = head;
        Node* curr = dumy->next;  //head of new LL
        Node* tmpCopy = curr;
        Node* trav = curr;

        while(tmp){
            if(tmp->random == NULL){
                trav->random = NULL;
            }else{
                int i=1;
                while(i < mp[tmp->random]){
                    tmpCopy = tmpCopy->next;
                    i++;
                }
                trav->random = tmpCopy;
                tmpCopy = curr;
            }
            
            tmp = tmp->next;
            trav = trav->next;
        }

        return curr;
    }
};