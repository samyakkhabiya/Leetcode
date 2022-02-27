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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenhead=new ListNode(-1);
        ListNode *oddhead=new ListNode(-1);
        ListNode* even=evenhead;
        ListNode* odd=oddhead;
        ListNode *itr=head;
        int i=1;
        while(itr){
            if(i%2==0){
                even->next=itr;
                even=even->next;
            }
            else{
                odd->next=itr;
                odd=odd->next;
            }
            i++;
            itr=itr->next;
        }
        odd->next=evenhead->next;
        even->next=NULL;
        head=oddhead->next;
        delete evenhead;
        delete oddhead;
        return head;
        
    }
};