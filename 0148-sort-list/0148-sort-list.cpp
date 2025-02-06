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
    ListNode* middleNode(ListNode* head) {
        ListNode*tortoise=head;
        ListNode*rabbit=head->next;
        while(rabbit!=NULL){
            rabbit=rabbit->next;
            if(rabbit!=NULL){
                rabbit=rabbit->next;
                tortoise=tortoise->next;
            }
        }
        return tortoise;
    }   

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode*left=list1;
        ListNode*right=list2;
        ListNode*ans=NULL;
        ListNode*mptr=NULL;
        if(left->val<=right->val){
            ans=left;
            mptr=ans;
            left=left->next;
        }
        else{
            ans=right;
            mptr=right;
            right=right->next;
        }
        while(left&&right){
            if(left->val<=right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        while(left){
            mptr->next=left;
            mptr=left;
            left=left->next;
        }
        while(right){
            mptr->next=right;
            mptr=right;
            right=right->next;
        }
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode*mid=middleNode(head);
        ListNode*left=head;
        ListNode*right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return mergeTwoLists(left,right);
    }
};