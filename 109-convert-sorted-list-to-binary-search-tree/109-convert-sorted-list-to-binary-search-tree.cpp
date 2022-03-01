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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ll;
    
    TreeNode* dfs(int i,int j){
        if(i>j)
            return NULL;
        int mid=(j+i)/2;
        TreeNode* ans=new TreeNode(ll[mid]);
        ans->left=dfs(i,mid-1);
        ans->right=dfs(mid+1,j);
        return ans;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }
        int mid=ll.size()/2;
        return dfs(0,ll.size()-1);
        // return NULL;
    }
};