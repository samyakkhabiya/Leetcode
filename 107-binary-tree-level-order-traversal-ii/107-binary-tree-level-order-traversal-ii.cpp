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
    vector<vector<int>> vc;
int h(TreeNode* root){
    if(!root)
        return 0;
    return 1+max(h(root->left),h(root->right));
}

void dfs(TreeNode* root,int level){
    if(!root)
        return;
    vc[level].push_back(root->val);
    dfs(root->left,level+1);
    dfs(root->right,level+1);
}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n=h(root);
    vc.resize(n);
    dfs(root,0);
        reverse(vc.begin(),vc.end());
    // vector<int> ans;
    // for(int i=n-1;i>=0;i--){
    //     for(auto j:vc[i]){
    //         ans.push_back(j);
    //     }
    //     // cout<<endl;
    // }
    return vc;
    }
};