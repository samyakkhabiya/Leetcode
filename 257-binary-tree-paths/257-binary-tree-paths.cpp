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
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(!root->left and !root->right){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        temp.pop_back();
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        vector<string> fans;
        for(auto i:ans){
            string t;
            for(auto j:i){
                t+=to_string(j)+"->";
            }
            if(t.size()){
                t.pop_back();
                t.pop_back();
            }
            fans.push_back(t);
        }
        return fans;
    }
};