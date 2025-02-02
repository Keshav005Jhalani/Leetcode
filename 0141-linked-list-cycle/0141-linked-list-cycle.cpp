/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<ListNode*,bool> map;
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(map[head]) return true;
            map[head]=true;
            head=head->next;
        }
        return false;
    }
};