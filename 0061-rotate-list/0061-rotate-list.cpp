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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        if(n==0) return head;
        k%=n;
        if(k==0) return head;
        temp=head;
        for(int i=0;i<=n-k-2;i++) temp=temp->next;
        ListNode*forward=temp->next;
        ListNode*newHead=forward;
        while(forward->next!=NULL) forward=forward->next;
        forward->next=head;
        temp->next=NULL;
        return newHead;
    }
};