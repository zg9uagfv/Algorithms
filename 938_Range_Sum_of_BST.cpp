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
    int sum(TreeNode *root, int min, int max)
    {
        int val = 0x00;
        if (NULL == root)
            return 0x00;
        
        if (root->val >= min && root->val <= max) {
            val = root->val;
        }
        
        return val + sum(root->left, min, max) + sum(root->right, min, max);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int min =0x00, max = 0x00;
        if (L > R) {
            max = L;
            min = R;
        } else {
            max = R;
            min = L;
        }
        return sum(root, min, max);
    }
};
