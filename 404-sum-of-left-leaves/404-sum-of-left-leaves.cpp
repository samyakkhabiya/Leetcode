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
    int ans=0;
    
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(root->left and (!root->left->left and !root->left->right))
            ans+=root->left->val;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};