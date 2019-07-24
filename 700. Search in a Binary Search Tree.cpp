/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find_node(TreeNode* root, int val) {
        if (NULL == root)
            return NULL;
        if (root->val == val) 
            return root;
        if (root->val > val) 
            return find_node(root->left, val);
        return find_node(root->right, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return this->find_node(root, val);
    }
};
