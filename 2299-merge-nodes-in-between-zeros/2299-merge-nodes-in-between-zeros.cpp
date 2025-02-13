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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode*writer=head;
        ListNode*reader=head->next;
        ListNode*writerPrev=head;
        while(reader!=NULL){
            while(reader->val!=0){
                sum+=reader->val;
                reader=reader->next;
            }
            writer->val=sum;
            writerPrev=writer;
            writer=writer->next;
            reader=reader->next;
            sum=0;
        }
        writerPrev->next=NULL;
        return head;
          
    }
};