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
    bool issametree(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL)return true;
        if(a == NULL || b == NULL)return false;
        if(a->val != b->val)return false;
        //only mistake is for symmetry i need to compare left child with right child and right with left child
        return issametree(a->left, b->right) && issametree(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return issametree(root->left, root->right);
    }
};