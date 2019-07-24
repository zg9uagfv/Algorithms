/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int depth(Node* root)
    {
        if (NULL == root) {
            return 0x00;
        }
        int max_depth = 0x01;
        for (auto child : root->children) {
            int depth = this->depth(child) + 1;
            if (max_depth < depth )
                max_depth = depth;
        } 
        return max_depth;
    }
                         
    int maxDepth(Node* root) {
        return this->depth(root);
    }
};
