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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftist= head;
        ListNode* rightist= head;
        
        ListNode* beforeLeftist= NULL;

        for (int i = 1; i < left; i++) {
            beforeLeftist = leftist;
            leftist = leftist->next;
        }

        ListNode* start= leftist;
        ListNode* prev= NULL;

        for(int i=0; i<=right-left ; i++){
            ListNode* temp= start->next;
            start->next= prev;
            prev= start;
            start= temp;
        }

        if(beforeLeftist!=NULL){
            beforeLeftist->next= prev;
        }
        else{
            head= prev;
        }

        leftist->next= start; 
        return head;
    }
};