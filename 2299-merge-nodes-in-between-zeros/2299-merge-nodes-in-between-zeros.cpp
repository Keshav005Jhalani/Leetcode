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
            if(reader->val!=0){
                sum+=reader->val;
            }
            else{

            writer->val=sum;
            writerPrev=writer;
            writer=writer->next;
            sum=0;
            }
            reader=reader->next;
        }
        writerPrev->next=NULL;
        return head;
          
    }
};