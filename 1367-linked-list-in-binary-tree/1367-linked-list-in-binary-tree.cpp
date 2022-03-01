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
    vector<int> vc;
    
    bool dfs2(TreeNode* root,int i,int n){
        if(!root)
            return false;
        if(vc[i]!=root->val)
            return false;
        if(i==n-1)
            return true;
        return dfs2(root->left,i+1,n) || dfs2(root->right,i+1,n);
    }
    
    bool dfs1(TreeNode* root){
        if(!root)
            return false;
        if(root->val==vc[0]){
            bool ch=dfs2(root,0,vc.size());
            if(ch)
                return true;
        }
        return dfs1(root->left) || dfs1(root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        while(head){
            vc.push_back(head->val);
            head=head->next;
        }
        return dfs1(root);
    }
};