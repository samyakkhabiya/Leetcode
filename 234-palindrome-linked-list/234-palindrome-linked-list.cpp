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
    bool isPalindrome(ListNode* head) {
        // ListNode* curr=head;
        stack<int>st;
        
        ListNode* current = head;
        
        while(current != NULL){
            st.push(current->val);
            current = current->next;
        }
        
        while(!st.empty()){
            int temp = st.top();
                        st.pop();
            
            if(head->val != temp){
                return false;
            }
            
            head= head->next;
        }
        
        return true;
    }
};