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
    map<int, map<int, vector<int>>> nodes;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> vec;
            for (auto q : p.second) {
                sort(q.second.begin(), q.second.end());
                vec.insert(vec.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(vec);
        }
        return ans;
    }
    void dfs(TreeNode* root, int x, int y) {
        if (root) {
            nodes[x][y].push_back(root -> val);
            dfs(root -> left, x - 1, y + 1);
            dfs(root -> right, x + 1, y + 1);
        }
    }
};