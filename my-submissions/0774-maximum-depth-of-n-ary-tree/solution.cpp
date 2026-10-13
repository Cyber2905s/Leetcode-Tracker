/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int depth(Node* root){
        if(!root) return 0;
        int maxi = 0;
        for(Node* child: root->children){
            maxi = max(maxi,depth(child));
        }
        return 1+maxi;
    }
public:
    int maxDepth(Node* root) {
        return depth(root); 
    }
};
