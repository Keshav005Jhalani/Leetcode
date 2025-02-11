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
    int getLen(ListNode*head){
        ListNode*temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode*prev=NULL;
        ListNode*curr=head;
        int pos=k;
        int len=getLen(head);
        if(len<k) return head;
        while(pos>0){
            ListNode*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            pos--;
        }
        ListNode*recursionKaHead=reverseKGroup(curr,k);
        head->next=recursionKaHead;
        return prev;
    }
};