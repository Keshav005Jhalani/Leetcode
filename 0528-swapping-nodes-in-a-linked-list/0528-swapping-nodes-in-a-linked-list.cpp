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

    ListNode* swapNodes(ListNode* head, int k) {
        int n=getLen(head);
        int lpos=k;
        int rpos=n-k+1;
        
        //case 1
        if(head==NULL||head->next==NULL) return head;
        
        //case 2
        if(n==2){
            ListNode*headNext=head->next;
            head->next=NULL;
            headNext->next=head;
            return headNext;
        }

        //case 3
        if(lpos==rpos) return head;

        //case 4
        if(k==1||k==n){
            if(rpos-lpos<0) swap(lpos,rpos);
            ListNode*left,*leftFor,*right,*rightPrev;
            left=head;
            leftFor=left->next;
            right=head;
            for(int i=0;i<=rpos-2;i++){
                rightPrev=right;
                right=right->next;
            }
            left->next=NULL;
            right->next=leftFor;
            rightPrev->next=left;
            return right;
        }

        //case 5
        if(rpos-lpos==1||lpos-rpos==1){
            if(rpos-lpos<0) swap(lpos,rpos);
            ListNode*left,*leftPrev,*right,*rightFor;
            left=head;
            for(int i=0;i<=lpos-2;i++){
                leftPrev=left;
                left=left->next;
            }
            right=left->next;
            rightFor=right->next;
            right->next=left;
            leftPrev->next=right;
            left->next=rightFor;
            return head;
        }

        else{ //general case if above all fails
            ListNode*left,*leftPrev,*leftFor,*right,*rightPrev,*rightFor;
            left=head;
            right=head;
            for(int i=0;i<=lpos-2;i++){
                leftPrev=left;
                left=left->next;
            }
            leftFor=left->next;
            for(int i=0;i<=rpos-2;i++){
                rightPrev=right;
                right=right->next;
            }
            rightFor=right->next;
            leftPrev->next=right;
            right->next=leftFor;
            rightPrev->next=left;
            left->next=rightFor;
            return head;

        }

        return head;
    }
};