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
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp=head;
        ListNode* prev=dummy;
        int k=1;
        while(temp->next!=nullptr) {temp=temp->next;k++;}
        temp=head;
        for(int i=0;i<k-n;i++){
            prev=temp;
            temp=temp->next;
        } 
        prev->next=temp->next;
        return dummy->next;
    }
};