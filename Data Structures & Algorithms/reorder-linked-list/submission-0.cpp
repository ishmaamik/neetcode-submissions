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
    void reorderList(ListNode* head) {

        ListNode* fast= head;
        ListNode* slow= head;
        
        while(fast && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }

        ListNode* second= slow->next;
        slow->next= NULL;
        ListNode* end= NULL;

        while(second){
            ListNode* temp= second->next;
            second->next= end;
            end= second;
            second= temp;    
        }

        ListNode* first= head;

        while(end){
            ListNode* temp1= end->next;
            ListNode* temp2= first->next;

            first->next= end;
            end->next= temp2;

            end= temp1;
            first= temp2;
        }

    }
};