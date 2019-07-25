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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (NULL == root) return NULL;
        TreeNode* head = root;
        if (head->val > L && head->val < R) {
            head->right = this->trimBST(head->right, L, R);
            head->left = this->trimBST(head->left, L, R);
        } else if (head->val < L) {
            head = this->trimBST(head->right, L, R);
        } else if (head->val == L) {
            head->right = this->trimBST(head->right, L, R);
            head->left = NULL;
        } else if (head->val == R) {
            head->left = this->trimBST(head->left, L, R);
            head->right = NULL;
        } else if (head->val > R) {
            head = this->trimBST(head->left, L, R);
        }
        return head;
    }
};
