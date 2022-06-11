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
    
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=0;
    void dfs(TreeNode* root, int target){
        if(!root)
            return;
        if(!root->left and !root->right){
            temp.push_back(root->val);
            sum+=root->val;
            if(sum==target)
                ans.push_back(temp);
            temp.pop_back();
            sum-=root->val;
            return;
        }
        
        temp.push_back(root->val);
        sum+=root->val;
        dfs(root->left,target);
        dfs(root->right,target);
        sum-=root->val;
        temp.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};