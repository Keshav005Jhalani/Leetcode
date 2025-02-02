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
        ListNode*rabbit=head;
        while(rabbit!=NULL){
            rabbit=rabbit->next;
            if(rabbit!=NULL){
                rabbit=rabbit->next;
                tortoise=tortoise->next;
            }
        }
        return tortoise;
    }

    ListNode* reverseList(ListNode*prev,ListNode*curr){
        if(curr==NULL) return prev;
        ListNode*forward=curr->next;
        curr->next=prev;
        return reverseList(curr,forward);
    }

    bool isPalindrome(ListNode* head) {
        ListNode*midNode=middleNode(head);
        ListNode*middleHead=reverseList(NULL,midNode);
        while(middleHead!=NULL&&head!=NULL){
            if(middleHead->val!=head->val) return false;
            middleHead=middleHead->next;
            head=head->next;
        }
        return true;
    }
};