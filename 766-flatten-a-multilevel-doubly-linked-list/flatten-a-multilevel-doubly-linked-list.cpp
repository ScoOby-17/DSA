/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tmp = head;

        while(tmp!=NULL){
            if(tmp->child != NULL){
                Node* next = tmp->next;
                Node* child = tmp->child;

                tmp->next = tmp->child;
                child->prev = tmp;
                tmp->child = NULL;

                while(child->next != NULL) child = child->next;

                child->next = next;
                if(next!=NULL) next->prev = child;
            }
            tmp = tmp->next;
        }

        return head;
    }
};