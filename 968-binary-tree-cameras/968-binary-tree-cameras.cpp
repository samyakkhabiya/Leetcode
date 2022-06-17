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
    int solve(TreeNode* root,TreeNode* p){
        if(!root)return 2;
        int l=solve(root->left,root);
        int r=solve(root->right,root);
        if(l==0||r==0||(p==NULL&&l==2&&r==2)){
            ans++;
            return 1;
        }
        if(l==1||r==1)return 2;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int k=solve(root,NULL);
        if(k==0)ans++;
        return ans;
    }
};