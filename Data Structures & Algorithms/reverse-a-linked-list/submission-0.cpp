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
    ListNode* reverseList(ListNode* head) {
        ListNode* right=head; ListNode* middle= head;
        ListNode* left= NULL;

        while(right!=NULL){
            middle= middle->next;
            right->next= left;
            left=right;
            right=middle;
        }
        return left;
    }
};