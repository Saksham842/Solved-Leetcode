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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>p;
        int n=0,ans=INT_MIN;
        while(temp!=nullptr)
        {
            p.push_back(temp->val);
            n++;
            temp=temp->next;
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,p[i]+p[n-1-i]);
        }
        return ans;
    }
};