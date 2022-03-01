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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first,*last,*itr=head;
        int len=1,f,l;
        while(itr){
            if(len==k){
                first=itr;
                f=itr->val;
            }
            len++;
            itr=itr->next;
        }
        itr=head;
        int slen=len-k;
        int i=1;
        while(itr){
            if(i==slen){
                last=itr;
                l=itr->val;
                break;
            }
            i++;
            itr=itr->next;
        }
        last->val=f;
        first->val=l;
        // swap(last->val,first->val);
        return head;
    }
};