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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        vector<ListNode*> ans;
        auto temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int partSize=n/k;
        int extraSize=n%k;
        temp=head;
        for(int i=0;i<=k-1;i++){
            ans.push_back(temp);
            int currSize=partSize+(extraSize>0?1:0);
            extraSize--;
            for(int j=0;j<=currSize-2;j++){
                if(temp) temp=temp->next;
            }
            if(temp){
                auto it=temp;
                temp=temp->next;
                it->next=NULL;
            }
        }
        return ans;
    }
};