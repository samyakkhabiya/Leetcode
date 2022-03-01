/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> vc;
    
    int h(Node* root){
        if(!root)
            return 0;
        return 1+max(h(root->left),h(root->right));
    }
    
    void dfs(Node* root,int level){
        if(!root)
            return;
        if(vc[level]){
            vc[level]->next=root;
            vc[level]=vc[level]->next;
            // if(root->val==5)
            //     cout<<"yes"<<endl;
        }
        else
            vc[level]=root;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        
    }
    
    Node* connect(Node* root) {
        int len=h(root);
        vc.resize(len,NULL);
        dfs(root,0);
        return root;
    }
};