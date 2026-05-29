/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head || head->next==NULL) return NULL;

        ListNode* slow= head;
        ListNode* fast= head;

        int i=0;

        while(i<n){
            fast= fast->next;
            i++;    //creates gap so that when fast becomes null, slow
            //is exactly at that point where we can delete the node next to
            //it
        }

        if(fast==NULL){
            return head->next;   //if fast becomes null by the time it
            //reaches i<n it means all the nodes are traversed by the fast
            //since fast is already null just return the head->next
            //instead of head= head->next then continuing
        }

        while(fast->next!=NULL){
            slow= slow->next;
            fast= fast->next;
        }

        slow->next= slow->next->next;

        return head;
    }
};