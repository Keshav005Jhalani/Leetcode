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
    ListNode* solve(ListNode*prev,ListNode*curr){
        if(curr==NULL) return prev;
        ListNode*forward=curr->next;
        curr->next=prev;
        return solve(curr,forward);
    }

    ListNode* reverseList(ListNode* head) {
        return solve(nullptr,head);
    }
};