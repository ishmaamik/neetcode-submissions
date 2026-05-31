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
    // Node* copyRandomList(Node* head) {
    //     if(head == NULL) return NULL;

    //     unordered_map<Node*, Node*> oldToNew;

    //     Node* start= head;

    //     //Build pointer copies of the old nodes
    //     while(start!=NULL){
    //         oldToNew[start]= new Node(start->val);
    //         start= start->next;
    //     }

    //     start= head;
    //     //Build random and next copies of the old nodes after building the
    //     //copies
    //     while(start!=NULL){
    //         oldToNew[start]->next= oldToNew[start->next];
    //         oldToNew[start]->random= oldToNew[start->random];
    //         start= start->next;
    //     }

    //     return oldToNew[head];
    // }

    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node* start= head;

        while(start!=NULL){
            Node* temp= start->next;
            
            Node* copy= new Node(start->val);
            start->next= copy;
            copy->next= temp;
            start= temp;
        }

        start= head;

        while(start!=NULL){
            start->next->random = start->random ? start->random->next : NULL;
            start= start->next->next; 
        } 

        Node* original= head;
        Node* copy= head->next;

        Node* newHead= copy;
        while(original!=NULL){
            original->next= copy->next;
            copy->next= copy->next ? copy->next->next : NULL;

            copy= copy->next;
            original= original->next;
        }

        return newHead;
    }
};