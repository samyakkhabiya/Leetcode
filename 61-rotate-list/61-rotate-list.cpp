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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* itr=head;
        if(!head || !head->next || k==0)
            return head;
        int count=0;
        while(itr){
            count++;
            itr=itr->next;
        }
        k=k%count;
        if(k==0)
            return head;
        // cout<<k<<endl;
        itr=head;
        ListNode* nhead;
        ListNode* prev;
        int temp=0;
        while(itr){
            if(count-temp==k){
                nhead=itr;
                ListNode* store=nhead;
                prev->next=NULL;
                while(store->next)
                    store=store->next;
                store->next=head;
            }
            temp++;
            prev=itr;
            itr=itr->next;
        }
        return nhead;
    }
};