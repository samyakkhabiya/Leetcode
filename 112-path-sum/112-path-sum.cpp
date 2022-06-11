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
    int sum=0;
    bool ans=false;
    void dfs(TreeNode* root, int target){
        if(!root)
            return;
        if(!root->left and !root->right){
            sum+=root->val;
            if(sum==target)
                ans=true;
            sum-=root->val;
            return;
        }
        
        sum+=root->val;
        dfs(root->left,target);
        dfs(root->right,target);
        sum-=root->val;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};