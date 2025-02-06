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
    ListNode* solve(ListNode* l1, ListNode* l2, int &carry) {
        if (!l1 && !l2 && carry == 0) return NULL;
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a + b + carry;
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        node->next = solve(l1 ? l1->next : NULL, l2 ? l2->next :NULL, carry);
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        return solve(l1, l2, carry);
    }
};

