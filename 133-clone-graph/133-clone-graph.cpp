/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node,int v,unordered_map<int,Node*>& mp){
        Node* n=new Node(v);
        mp[v]=n;
        for(int i=0;i<node->neighbors.size();i++){
            if(mp.find(node->neighbors[i]->val)!=mp.end()){
                n->neighbors.push_back(mp[node->neighbors[i]->val]);
                continue;
            }
            Node* ans=solve(node->neighbors[i],node->neighbors[i]->val,mp);
            n->neighbors.push_back(ans);
        }
        return n;
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<int,Node*> mp ;
        return solve(node,1,mp);
    }
};